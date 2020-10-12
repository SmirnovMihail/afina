#ifndef AFINA_STORAGE_STRIPEDLOCK_LRU_H
#define AFINA_STORAGE_STRIPEDLOCK_LRU_H

#include <map>
#include <memory>
#include <mutex>
#include <string>

#include <afina/Storage.h>
#include "ThreadSafeSimpleLRU.h"

namespace Afina {
namespace Backend {


class StripedLockLRU : public Afina :: Storage
{
public:
    StripedLockLRU(std::size_t memory_limit = 1024, std::size_t stripe_count = 4);

    // Implements Afina::Storage interface
    bool Put(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool PutIfAbsent(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool Set(const std::string &key, const std::string &value) override;

    // Implements Afina::Storage interface
    bool Delete(const std::string &key) override;

    // Implements Afina::Storage interface
    bool Get(const std::string &key, std::string &value) override;

    ~StripedLockLRU();
    
private:

    ThreadSafeSimpleLRU* BuildStripedLRU(std::size_t memory_limit, std::size_t stripe_count);
    ThreadSafeSimpleLRU* shards;

    size_t stripes_number;
};


} // namespace Backend
} // namespace Afina

#endif // AFINA_STORAGE_STRIPEDLOCK_LRU_H
