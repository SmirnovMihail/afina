#ifndef AFINA_CONCURRENCY_EXECUTOR_H
#define AFINA_CONCURRENCY_EXECUTOR_H

#include <condition_variable>
#include <functional>
#include <memory>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <atomic>
#include <iostream>

//#include "src/concurrency/CMakeFiles/Executor.cpp"

namespace Afina {
namespace Concurrency {

class Executor;
void perform(Executor *executor);

/**
 * # Thread pool
 */
class Executor {
public:
    enum class State {
        // Threadpool is fully operational, tasks could be added and get executed
        kRun,

        // Threadpool is on the way to be shutdown, no ned task could be added, but existing will be
        // completed as requested
        kStopping,

        // Threadppol is stopped
        kStopped
    };

    Executor(std::function<void(const std::string &msg)> &log_err_, size_t min = 4, size_t max = 16, size_t queue_max = 1000, size_t time_ms = 10000)
    {
        min_workers = min;
        max_workers = max;
        max_queue_size = queue_max;
        idle_time = time_ms;
        state = State :: kRun;

        queue_size = 0;
        busy_workers = 0;
        existing_workers = min;
        log_err = log_err_;


        for (auto i=0; i < min; i++)
        {
            //auto thread = std :: thread(perform, this);
        log_err("*2.5\n");
            //threads.emplace_back(std :: thread([this] { return perform(this); }));
            std :: thread th([this] { return perform(this); });
            th.detach();
        log_err("*2.6\n");
        }
    }
    ~Executor()
    {
        Stop(true);
    };

    /**
     * Signal thread pool to stop, it will stop accepting new jobs and close threads just after each become
     * free. All enqueued jobs will be complete.
     *
     * In case if await flag is true, call won't return until all background jobs are done and all threads are stopped
     */
    void Stop(bool await = false)
    {
        state = State :: kStopping;
        cv_empty.notify_all();
        if (await == true)
        {
            std::unique_lock<std::mutex> lock(this->mutex);

            while (existing_workers.load() > 0)
            {
                cv_finished.wait(lock);
            }
            state = State :: kStopped;
        }
    }

    /**
     * Add function to be executed on the threadpool. Method returns true in case if task has been placed
     * onto execution queue, i.e scheduled for execution and false otherwise.
     *
     * That function doesn't wait for function result. Function could always be written in a way to notify caller about
     * execution finished by itself
     */
    template <typename F, typename... Types> bool Execute(F &&func, Types... args) {
        // Prepare "task"
        auto exec = std::bind(std::forward<F>(func), std::forward<Types>(args)...);

        std::unique_lock<std::mutex> lock(this->mutex);
        if (state != State::kRun)
        {
            return false;
        }
        log_err("*3\n");

        while (queue_size > max_queue_size)
        {
            cv_full.wait(lock);
        }
        log_err("*4\n");

        // Enqueue new task
        tasks.push_back(exec);
        queue_size++;

        auto workers = busy_workers.load();
        auto existing = existing_workers.load();

        if (workers == existing && existing < max_workers)
        {
            log_err("______________________________________________________\n");
            //auto thread = std :: thread(perform, this);
            //threads.emplace_back(std :: thread(perform, this));
            std :: thread th([this] { return perform(this); });
            th.detach();
            existing_workers.fetch_add(1);
        }
        cv_empty.notify_all();

        return true;
    }

private:
    // No copy/move/assign allowed

    Executor(const Executor &);            // = delete;
    Executor(Executor &&);                 // = delete;
    Executor &operator=(const Executor &); // = delete;
    Executor &operator=(Executor &&);      // = delete;

    /**
     * Main function that all pool threads are running. It polls internal task queue and execute tasks
     */
    friend void perform(Executor *executor)
    {
        while (executor -> state != executor->State :: kStopped)
        {
            bool empty;
            std :: function<void()> task;
            {
                std :: unique_lock<std :: mutex> lock(executor->mutex);

                while (empty = executor->tasks.empty())
                {
                    auto res = executor->cv_empty.wait_for(lock,
                                                           std::chrono::milliseconds(executor->idle_time));
                    if (res == std::cv_status::timeout ||
                        executor->existing_workers.load() > executor->max_workers)
                    {
                        /*auto this_thread_id = std::this_thread::get_id();
                        for (std :: vector<std :: thread> :: iterator it = executor->threads.begin(); it != executor->threads.end(); it++)
                        {
                            if (it->get_id() == this_thread_id)
                            {
                                executor->log_err("finishing\n");
                                executor->threads.erase(it);
                                executor->log_err("finishing complete halfly\n");
                                executor->existing_workers.fetch_sub(1);
                                executor->cv_finished.notify_one();
                            }
                        }*/
                        executor->existing_workers.fetch_sub(1);
                        executor->cv_finished.notify_one();
                        return;
                    }

                    if (empty && executor -> state == executor->State :: kStopping)
                    {
                        executor->existing_workers.fetch_sub(1);
                        executor->cv_finished.notify_one();
                        return;
                    }
                }

                //if (empty && )
                //    return;

                task = std::move(executor->tasks.front());
                executor->tasks.pop_front();

                if (executor->state == executor->State :: kStopping && executor->busy_workers == 0)
                    executor->cv_finished.notify_one();

                if (executor->queue_size == executor->max_queue_size)
                    executor->cv_full.notify_one();

                executor->queue_size--;
            }
            executor->busy_workers.fetch_add(1);
            auto this_thread_id = std::this_thread::get_id();
            std :: cout << this_thread_id << "\n";
            task();
            executor->busy_workers.fetch_sub(1);
                //if (executor -> state != kStopping)
        }
    }

    /**
     * Mutex to protect state below from concurrent modification
     */
    std::mutex mutex;

    /**
     * Conditional variable to await new data in case of empty queue
     */
    std :: condition_variable cv_empty;
    std :: condition_variable cv_full;
    std :: condition_variable cv_finished;

    /**
     * Vector of actual threads that perorm execution
     */
    std :: vector<std :: reference_wrapper<std :: thread>> threads;

    /**
     * Task queue
     */
    std::deque<std::function<void()>> tasks;

    /**
     * Flag to stop bg threads
     */
    State state;

    size_t max_queue_size;
    size_t queue_size;
    size_t idle_time; //milliseconds

    size_t min_workers;
    size_t max_workers;
    std :: atomic<size_t> existing_workers;
    std :: atomic<size_t> busy_workers;

    std::function<void(const std::string &msg)> log_err;
};

} // namespace Concurrency
} // namespace Afina

#endif // AFINA_CONCURRENCY_EXECUTOR_H
