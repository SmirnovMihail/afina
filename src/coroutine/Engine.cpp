#include <afina/coroutine/Engine.h>

#include <csetjmp>
#include <cstring>
#include <stdio.h>
#include <string.h>

namespace Afina {
namespace Coroutine {

void Engine :: Store(context &ctx)
{
    char addr;
    ctx.Hight = &addr;

    if (ctx.Hight < ctx.Low)
    {
        auto tmp = ctx.Hight;
        ctx.Hight = ctx.Low;
        ctx.Low = tmp;
    }

    std :: size_t stackSize = ctx.Hight - ctx.Low;
    if (stackSize > std :: get<1>(ctx.Stack) || stackSize * 2 < std :: get<1>(ctx.Stack))
    {
        delete[] std :: get<0>(ctx.Stack);
        std :: get<0>(ctx.Stack) = new char[stackSize];
        std :: get<1>(ctx.Stack) = stackSize;
    }
    // for (size_t i = 0; i < stackSize; i ++)
    // {
    //     std :: get<0>(ctx.Stack)[i] = *(ctx.Low + i);
    //     printf("ok\n");
    // }
    std :: memcpy(std :: get<0>(ctx.Stack), ctx.Low, stackSize);
}


void Engine :: Restore(context &ctx)
{
    char curr_sp;
    while ((&curr_sp >= ctx.Low) && (&curr_sp <= ctx.Hight))
    {
        Restore(ctx);
    }

    std :: memcpy(ctx.Low, std :: get<0>(ctx.Stack), ctx.Hight - ctx.Low);
    std :: longjmp(ctx.Environment, 1);
}


void Engine::yield()
{
    sched();
}


void Engine :: sched(void *routine_)
{
    if (routine_ == nullptr)
    {
        if (alive != nullptr)
        {
            if (alive != cur_routine)
            {
                sched(alive);
            }
            else if (alive->next != nullptr)
            {
                sched(alive->next);
            }
            else
                //std :: longjmp(idle_ctx->Environment, 1);
                Restore(*idle_ctx);
        }
        else
            Restore(*idle_ctx);
            //std :: longjmp(idle_ctx->Environment, 1);
    }
    else if (routine_ != cur_routine)
    {
        Store(*cur_routine);
        if (setjmp(cur_routine->Environment) == 0)
        {
            cur_routine = (context*)routine_;
            Restore(*cur_routine);
            //std :: longjmp(cur_routine->Environment, 1);
        }
        else
            return;
    }
}


void Engine :: delete_from_list(context *ptr)
{
    if (ptr->next != nullptr)
    {
        ptr->prev->next = ptr->next;
    }
    else
        ptr->prev->next = nullptr;

    if (ptr->prev != nullptr)
    {
        ptr->next->prev = ptr->prev;
    }
    else
        ptr->next->prev = nullptr;
}


Engine :: context* Engine :: push_front_in_list(context *list_begin, context *ptr)
{
    ptr->next = list_begin;
    list_begin = ptr;

    if (ptr->next != nullptr)
    {
        ptr->next->prev = ptr;
    }

    return list_begin;
}


void Engine :: block(void *routine_)
{
    if (routine_ != nullptr)
    {
        context *tmp = alive;
        while ((tmp != nullptr) || (tmp != routine_))
        {
            tmp = tmp->next;
        }
        if (tmp != nullptr)
        {
            delete_from_list(tmp);
            blocked = push_front_in_list(blocked, tmp);
        }
        else
            return;
    }
    else
        block(cur_routine);
}


void Engine :: unblock(void *routine_)
{
    context* tmp = blocked;
    while ((tmp != nullptr) || (tmp != routine_))
    {
        tmp = tmp->next;
    }
    if (tmp != nullptr)
    {
        delete_from_list(tmp);
        alive = push_front_in_list(alive, tmp);
    }
}


Engine :: ~Engine()
{
    while (alive != nullptr)
    {
        context *tmp = alive;
        alive = alive->next;
        delete[] std :: get<0>(tmp->Stack);
        delete tmp;
    }
    while (blocked != nullptr)
    {
        context *tmp = blocked;
        blocked = blocked->next;
        delete[] std :: get<0>(tmp->Stack);
        delete tmp;
    }
    if (StackBottom)
    {
        delete[] std :: get<0>(idle_ctx->Stack);
        delete idle_ctx;
    }
}

} // namespace Coroutine
} // namespace Afina
