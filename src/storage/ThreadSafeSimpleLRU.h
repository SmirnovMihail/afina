#ifndef AFINA_STORAGE_THREAD_SAFE_SIMPLE_LRU_H
#define AFINA_STORAGE_THREAD_SAFE_SIMPLE_LRU_H

#include <map>
#include <mutex>
#include <string>

#include "SimpleLRU.h"

namespace Afina {
namespace Backend {

/**
 * # SimpleLRU thread safe version
 *
 *
 */
class ThreadSafeSimplLRU : public SimpleLRU {
public:
    ThreadSafeSimplLRU(size_t max_size = 1024) : SimpleLRU(max_size) {}
    ~ThreadSafeSimplLRU() {}

    // see SimpleLRU.h
    bool Put(const std::string &key, const std::string &value) override {
        // std :: cout << "Try to get mutex Put" << std :: endl;
        std :: unique_lock<std :: recursive_mutex> ul(m);
        // std :: cout << "Mutex is mine" << std :: endl;
        return SimpleLRU::Put(key, value);
    }

    // see SimpleLRU.h
    bool PutIfAbsent(const std::string &key, const std::string &value) override {
        // std :: cout << "try to get mutex PutIfAbsent" << std :: endl;
        std :: unique_lock<std :: recursive_mutex> ul(m);
        // std :: cout << "mutex is mine" << std :: endl;
        return SimpleLRU::PutIfAbsent(key, value);
    }

    // see SimpleLRU.h
    bool Set(const std::string &key, const std::string &value) override {
        // std :: cout << "try to get mutex Set" << std :: endl;
        std :: unique_lock<std :: recursive_mutex> ul(m);
        // std :: cout << "mutex is mine" << std :: endl;
        return SimpleLRU::Set(key, value);
    }

    // see SimpleLRU.h
    bool Delete(const std::string &key) override {
        // std :: cout << "try to get mutex Delete" << std :: endl;
        std :: unique_lock<std :: recursive_mutex> ul(m);
        // std :: cout << "mutex is mine" << std :: endl;
        return SimpleLRU::Delete(key);
    }

    // see SimpleLRU.h
    bool Get(const std::string &key, std::string &value) override {
        // std :: cout << "try to get mutex Get" << std :: endl;
        std :: unique_lock<std :: recursive_mutex> ul(m);
        // std :: cout << "mutex is mine" << std :: endl;
        return SimpleLRU::Get(key, value);
    }

    // static std :: mutex m;
private:
    std :: recursive_mutex m;
};

} // namespace Backend
} // namespace Afina

#endif // AFINA_STORAGE_THREAD_SAFE_SIMPLE_LRU_H
