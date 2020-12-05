#include <afina/concurrency/Executor.h>

namespace Afina {
namespace Concurrency {
/*
void perform(Executor *executor)
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
                    auto this_thread_id = std::this_thread::get_id();
                    for (auto it = executor->threads.begin(); it != executor->threads.end(); it++)
                    {
                        if (it->get_id() == this_thread_id)
                        {
                            executor->threads.erase(it);
                            executor->existing_workers.fetch_sub(1);
                            executor->cv_finished.notify_one();
                        }
                    }
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
        task();
        executor->busy_workers.fetch_sub(1);
            //if (executor -> state != kStopping)
    }
}
*/
} // namespace Concurrency
} // namespace Afina
