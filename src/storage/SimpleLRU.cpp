#include "SimpleLRU.h"
#include "stdio.h"

namespace Afina {
namespace Backend {


// See MapBasedGlobalLockImpl.h
bool SimpleLRU :: Put(const std :: string &key, const std :: string &value)
{
  size_t size = key.size() + value.size();

  if (size > _max_size) //check if size is correct
  {
    return false;
  }

  while (size > free_space) //delete last recently used elements to free space
  {
    const std :: string key_to_delete = lru_list.get_head_key();

    _lru_index.erase(std :: reference_wrapper<const std :: string>(key_to_delete)); //delete from map
    free_space += lru_list.delete_lru(); //delete from list
  }

  if (!_lru_index.count(key)) //insert or set value
  {
    free_space -= size;

    lru_node *new_elem = lru_list.add_in_end(key, value);
    _lru_index.insert(std :: make_pair(std :: reference_wrapper<std :: string>(new_elem->key),
                                       std :: reference_wrapper<lru_node>(*new_elem)));
    return true;
  }
  else
    return Set(key, value);
}


// See MapBasedGlobalLockImpl.h
bool SimpleLRU::PutIfAbsent(const std :: string &key, const std :: string &value)
{
  if (!_lru_index.count(key))
  {
    return Put(key, value);
  }
  else
    return false;
}


// See MapBasedGlobalLockImpl.h
bool SimpleLRU :: Set(const std :: string &key, const std :: string &value)
{
  auto pair = _lru_index.find(key);

  if (pair != _lru_index.end())
  {
    std :: string &value_ref = pair -> second.get().value; // get refernce to changing value

    free_space += value_ref.size() - value.size();
    value_ref = value;

    return true;
  }
  else
    return false;
}


// See MapBasedGlobalLockImpl.h
bool SimpleLRU :: Delete(const std :: string &key)
{
  auto pair = _lru_index.find(key);

  if (pair != _lru_index.end())
  {
    lru_node &node = pair -> second;
    _lru_index.erase(std :: reference_wrapper<const std :: string>(key)); //delete from map
    free_space += lru_list.delete_element(node); //delete from list

    return true;
  }
  else
    return false;
}


// See MapBasedGlobalLockImpl.h
bool SimpleLRU :: Get(const std :: string &key, std :: string &value)
{
  if (_lru_index.count(key))
  {
    auto pair = _lru_index.find(key);
    value = pair -> second.get().value;
    return true;
  }
  else
    return false;
}


const std :: string& SimpleLRU :: lru_node_list :: get_head_key()
{
  return _lru_head -> key;
}


size_t SimpleLRU :: lru_node_list :: delete_lru()
{
  const std :: string &key = _lru_head -> key;
  size_t size_info = _lru_head -> key.size() + _lru_head -> value.size();

  if (_lru_head -> next == nullptr) //only head in list
    _lru_head.reset();
  else
    _lru_head = std :: move(_lru_head -> next);

  return size_info;
}


size_t SimpleLRU :: lru_node_list :: delete_element(lru_node &element)
{
  size_t size_info = element.key.size() + element.value.size();

  if (element.prev == nullptr && element.next == nullptr) //only head in list
  {
    _lru_head.reset();
  }
  else if (element.prev == nullptr) // elem == head
  {
    _lru_head = std :: move(_lru_head->next);
  }
  else if (element.next == nullptr) // elem == tail
  {
    _lru_tail = element.prev;
    _lru_tail -> next.reset();
  }
  else // other cases
    element.prev->next = std :: move(element.next);

  return size_info;
}


SimpleLRU :: lru_node* SimpleLRU :: lru_node_list :: add_in_end(const std :: string &key,
                                                   const std :: string &value)
{
    std :: unique_ptr<lru_node> new_node_ptr(new lru_node(key, value));

    if (!_lru_head) //there are no nodes in list
    {
      _lru_head = std :: move(new_node_ptr);
      _lru_tail = _lru_head.get();
    }
    else
    {
      _lru_tail -> next =  std :: move(new_node_ptr);
      _lru_tail -> next -> prev = _lru_tail;
      _lru_tail = _lru_tail -> next.get();
    }

    return _lru_tail;
}


SimpleLRU :: lru_node_list :: ~lru_node_list()
{
  while (_lru_head && (_lru_tail != _lru_head.get())) //delete sequently from tail to head
  {
    _lru_tail = _lru_tail -> prev;
    _lru_tail -> next.reset();
  }
  _lru_head.reset();
}

} // namespace Backend
} // namespace Afina
