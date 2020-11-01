#include "StripedLockLRU.h"
#include "stdio.h"
#include <functional>

namespace Afina {
namespace Backend {

std :: unique_ptr<ThreadSafeSimpleLRU[]> StripedLockLRU :: BuildStripedLRU(std::size_t memory_limit, std::size_t stripe_count)
{
    std :: unique_ptr<ThreadSafeSimpleLRU[]> shards{new ThreadSafeSimpleLRU[stripe_count]};
    if (memory_limit < 1024)
    {
        throw std :: runtime_error("Memory limit is too small");
    }
    // Вот тут можно получить не корректное число, вроде 1 байт размера пары ключ/значение.
    // В таком случае нужно бросить пользователю исключение на старте и сказать, что параметры выбранны
    // не верно
    //
    // Протокол требует, чтобы мы могли вставить максимум 1MB данных на 1 ключ
    std::size_t stripe_limit = memory_limit / stripe_count;

    for (size_t i = 0; i < stripe_count; i++)
    {
        shards[i].set_max_size(stripe_limit); //= ThreadSafeSimpleLRU(stripe_limit);
    }

    return shards;
}

StripedLockLRU :: StripedLockLRU(std::size_t memory_limit, std::size_t stripe_count) : stripes_number(stripe_count)
{
    shards = BuildStripedLRU(memory_limit, stripe_count);
}


bool StripedLockLRU :: Put(const std::string &key, const std::string &value)
{
    size_t hash = std :: hash<std :: string>{}(key);
    return shards[hash % stripes_number].Put(key, value);
}

// see SimpleLRU.h
bool StripedLockLRU :: PutIfAbsent(const std::string &key, const std::string &value)
{
    size_t hash = std :: hash<std :: string>{}(key);
    return shards[hash % stripes_number].PutIfAbsent(key, value);
}

// see SimpleLRU.h
bool StripedLockLRU :: Set(const std::string &key, const std::string &value)
{
    size_t hash = std :: hash<std :: string>{}(key);
    return shards[hash % stripes_number].Set(key, value);
}

// see SimpleLRU.h
bool StripedLockLRU :: Delete(const std::string &key)
{
    size_t hash = std :: hash<std :: string>{}(key);
    return shards[hash % stripes_number].Delete(key);
}

// see SimpleLRU.h
bool StripedLockLRU :: Get(const std::string &key, std::string &value)
{
    size_t hash = std :: hash<std :: string>{}(key);
    return shards[hash % stripes_number].Get(key, value);
}

StripedLockLRU :: ~StripedLockLRU()
{
}

} // namespace Backend
} // namespace Afina
