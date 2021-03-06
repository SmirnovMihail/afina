#include "Connection.h"

#include <iostream>
#include <sys/socket.h>

namespace Afina {
namespace Network {
namespace MTnonblock {

// See Connection.h
void Connection::Start()
{
    std::cout << "Start" << std::endl;
    _event.events |= EPOLLIN;
    _event.events |= EPOLLET;
    running.store(true);
}

// See Connection.h
void Connection::OnError()
{
     std::cout << "OnError" << std::endl;
     perror("Somekind of error in connection");
     OnClose();
}

// See Connection.h
void Connection::OnClose()
{
    std::cout << "OnClose" << std::endl;
    running.store(false);
    //_event.events = 0;
    close(_socket);
}

// See Connection.h
void Connection::DoRead()
{
    //std::unique_lock<std::mutex> lock(_mutex);

    std::cout << "DoRead" << std::endl;
    uint32_t new_event = 0;
    int readed_bytes = -1;
    try
    {
        while ((readed_bytes = read(_socket, client_buffer + read_offset, sizeof(client_buffer) - read_offset)) > 0)
        {
            _logger->debug("Got {} bytes from socket", readed_bytes);
            // Single block of data readed from the socket could trigger inside actions a multiple times,
            // for example:
            // - read#0: [<command1 start>]
            // - read#1: [<command1 end> <argument> <command2> <argument for command 2> <command3> ... ]
            while (readed_bytes > 0)
            {
                _logger->debug("Process {} bytes", readed_bytes);
                // There is no command yet
                if (!command_to_execute)
                {
                    std::size_t parsed = 0;
                    if (parser.Parse(client_buffer, readed_bytes, parsed))
                    {
                        // There is no command to be launched, continue to parse input stream
                        // Here we are, current chunk finished some command, process it
                        _logger->debug("Found new command: {} in {} bytes", parser.Name(), parsed);
                        command_to_execute = parser.Build(arg_remains);
                        if (arg_remains > 0)
                        {
                            arg_remains += 2;
                        }
                    }

                    // Parsed might fails to consume any bytes from input stream. In real life that could happens,
                    // for example, because we are working with UTF-16 chars and only 1 byte left in stream
                    if (parsed == 0)
                    {
                        break;
                    }
                    else
                    {
                        read_offset = readed_bytes - parsed;
                        std::memmove(client_buffer, client_buffer + parsed, read_offset);
                        readed_bytes -= parsed;
                    }
                }

                // There is command, but we still wait for argument to arrive...
                if (command_to_execute && arg_remains > 0)
                {
                    _logger->debug("Fill argument: {} bytes of {}", readed_bytes, arg_remains);
                    // There is some parsed command, and now we are reading argument
                    std::size_t to_read = std::min(arg_remains, std::size_t(readed_bytes));
                    argument_for_command.append(client_buffer, to_read);

                    read_offset = readed_bytes - to_read;
                    std::memmove(client_buffer, client_buffer + to_read, read_offset);
                    arg_remains -= to_read;
                    readed_bytes -= to_read;
                }

                // Thre is command & argument - RUN!
                if (command_to_execute && arg_remains == 0)
                {
                    _logger->debug("Start command execution");

                    std::string result;
                    if (argument_for_command.size())
                    {
                        argument_for_command.resize(argument_for_command.size() - 2);
                    }
                    _logger->debug("Argument for command ({})", argument_for_command);
                    command_to_execute->Execute(*pStorage, argument_for_command, result);

                    // Send response
                    result += "\r\n";
                    _logger->debug("Result ({})", result);

                    std::unique_lock<std::mutex> lock(_mutex);
                    {
                        size_t current_size = output.size();

                        _logger->debug("Curr size = {}", current_size);

                        output.push_back(result);

                        if (current_size == 0) //queue was empty
                        {
                            _event.events |= EPOLLOUT;
                        }
                        if (current_size >= max_q_size)
                        {
                            //new_event |= EPOLLIN;
                            _event.events &= ~EPOLLIN;
                            break;
                        }
                    }
                    // if (new_event != _event.events)
                    // {
                    //     _event.events = new_event;
                    // }
                    // if (send(client_socket, result.data(), result.size(), 0) <= 0)
                    // {
                    //     throw std::runtime_error("Failed to send response");
                    // }
                    //
                    // Prepare for the next command
                    command_to_execute.reset();
                    argument_for_command.resize(0);
                    parser.Reset();
                }
            } // while (readed_bytes)
        }

        if (readed_bytes == 0)
        {
            _logger->debug("Connection closed");
            OnClose();
            //running.store(false);
        }
        else if ((errno != EAGAIN) && (readed_bytes == -1))
        {
            throw std::runtime_error(std::string(strerror(errno)));
        }

    }
    catch (std::runtime_error &ex)
    {
        _logger->error("Failed to process connection on descriptor {}: {}", _socket, ex.what());
        OnClose();
    }
}

// See Connection.h
void Connection::DoWrite()
{
    std::unique_lock<std::mutex> lock(_mutex);

    std::cout << "DoWrite" << std::endl;
    uint32_t new_event = 0;
    size_t current_size = output.size();

    while (current_size > 0)
    {
        auto msg = output.front();
        size_t size = msg.size();
        int len = send(_socket, msg.data() + write_offset, size - write_offset, 0);
        _logger->debug("msg = {} ||| {}", msg.data(), msg.data() + write_offset);
        if (len > 0)
        {
            write_offset += len;
            if (write_offset == size)
            {
                output.pop_front();
                current_size--;
                write_offset = 0;
            }
        }
        else if ((len == -1) && (errno != EAGAIN))
        {
            OnClose();
            _logger->error("Failed to process connection on descriptor {}", _socket);
            break;
        }
    }

    if (current_size == 0)
    {
        _event.events &= ~EPOLLOUT;
    }
    if (current_size < max_q_size)
    {
        _event.events |= EPOLLIN;
    }

    // if (new_event != _event.events)
    // {
    //     _event.events = new_event;
    // }
}

} // namespace MTnonblock
} // namespace Network
} // namespace Afina
