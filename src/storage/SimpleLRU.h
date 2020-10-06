#ifndef AFINA_STORAGE_SIMPLE_LRU_H
#define AFINA_STORAGE_SIMPLE_LRU_H

#include <map>
#include <memory>
#include <mutex>
#include <string>

#include <afina/Storage.h>

namespace Afina {
namespace Backend {

/**
 * # Map based implementation
 * That is NOT thread safe implementaiton!!
 */
class SimpleLRU : public Afina::Storage {
public:
    SimpleLRU(size_t max_size = 1024) : _max_size(max_size), free_space(_max_size) {}

    ~SimpleLRU() {
        _lru_index.clear(); //list cleaning is in the list destructor
    }

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

private:
    void release_memory(size_t &size);
    
    // LRU cache node
    using lru_node = struct lru_node
    {
        std::string key;
        std::string value;
        lru_node *prev;
        std::unique_ptr<lru_node> next;

        lru_node(const std :: string &k, const std :: string &v) : key(k), value(v), prev(nullptr), next(nullptr){}
    };

    class lru_node_list
    {
      std::unique_ptr<lru_node> _lru_head;
      lru_node *_lru_tail;

    public:

      lru_node_list() : _lru_head(nullptr), _lru_tail(nullptr) {}
      ~lru_node_list();

      const std :: string& get_head_key(); //returns key of head node
      size_t delete_lru(); //delete node from head
      size_t delete_node(lru_node& element); //delete node using its link
      void update_node_usage_status(lru_node& node); //transfers node in the end of list;

      SimpleLRU :: lru_node* add_in_end(const std :: string &key, const std :: string &value); //adds pair in end
    };

    // Maximum number of bytes could be stored in this cache.
    // i.e all (keys+values) must be less the _max_size
    size_t _max_size;

    size_t free_space;
    // Main storage of lru_nodes, elements in this list ordered descending by "freshness": in the head
    // element that wasn't used for longest time.
    //
    // List owns all nodes
    lru_node_list lru_list;
    // Index of nodes from list above, allows fast random access to elements by lru_node#key
    std::map<std::reference_wrapper<const std::string>, std::reference_wrapper<lru_node>, std::less<std::string>> _lru_index;
};

} // namespace Backend
} // namespace Afina

#endif // AFINA_STORAGE_SIMPLE_LRU_H
