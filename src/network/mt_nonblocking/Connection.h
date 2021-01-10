#ifndef AFINA_NETWORK_MT_NONBLOCKING_CONNECTION_H
#define AFINA_NETWORK_MT_NONBLOCKING_CONNECTION_H

#include <string>
#include <mutex>
#include <deque>

#include <sys/epoll.h>
#include <spdlog/logger.h>

#include <afina/Storage.h>
#include <afina/execute/Command.h>
#include <afina/logging/Service.h>

#include "protocol/Parser.h"

namespace Afina {
namespace Network {
namespace MTnonblock {

    class Connection
    {
    public:

        Connection(int s, std :: shared_ptr<spdlog :: logger> &_log, std::shared_ptr<Afina :: Storage> &ps)
                   :_socket(s), _logger(_log), pStorage(ps), max_q_size(100), write_offset(0), read_offset(0)
        {
            std :: memset(&_event, 0, sizeof(struct epoll_event));
            _event.data.ptr = this;
            running.store(false);
            //client_buffer.resize(4096);
        }

        inline bool isAlive() const { return running.load(); }

        void Start();

    protected:
        void OnError();
        void OnClose();
        void DoRead();
        void DoWrite();

    private:
        friend class Worker;
        friend class ServerImpl;

        int _socket;
        struct epoll_event _event;

        std :: atomic<bool> running;
        std :: size_t arg_remains;
        Protocol :: Parser parser;
        std :: string argument_for_command;
        std :: unique_ptr<Execute::Command> command_to_execute;

        std :: shared_ptr<spdlog::logger> _logger;
        std :: shared_ptr<Afina::Storage> pStorage;

        std :: deque<std :: string> output;
        char client_buffer[4096];

        size_t max_q_size;
        size_t read_offset;
        size_t write_offset;

        std :: mutex _mutex;
    };

} // namespace MTnonblock
} // namespace Network
} // namespace Afina

#endif // AFINA_NETWORK_MT_NONBLOCKING_CONNECTION_H
