#include "SimpleLRU.h"
#include "stdio.h"

namespace Afina {
namespace Backend {


void SimpleLRU :: release_memory(size_t &size)
{
  while (size > free_space) //delete last recently used elements to free space
  {
    const std :: string key_to_delete = lru_list.get_head_key();

    _lru_index.erase(std :: reference_wrapper<const std :: string>(key_to_delete)); //delete from map
    free_space += lru_list.delete_lru(); //delete from list
  }
}


// See MapBasedGlobalLockImpl.h
bool SimpleLRU :: Put(const std :: string &key, const std :: string &value)
{
  size_t size = key.size() + value.size();

  if (size > _max_size) //check if size is correct
  {
    return false;
  }

  auto pair = _lru_index.find(key);

  if (pair == _lru_index.end()) //insert or set value
  {
    put_process(key, value);
  }
  else
  {
    set_process(pair, value);
  }

  return true;
}


void SimpleLRU :: put_process(const std :: string &key, const std :: string &value)
{
  size_t size = key.size() + value.size();

  release_memory(size);
  free_space -= size;

  lru_node *new_elem = lru_list.add_in_end(key, value);
  _lru_index.insert(std :: make_pair(std :: reference_wrapper<std :: string>(new_elem->key),
                                     std :: reference_wrapper<lru_node>(*new_elem)));
}


void SimpleLRU :: set_process(const map_type :: iterator &pair,
                              const std :: string &value)
{
  size_t value_size = value.size();

  std :: string &value_ref = pair -> second.get().value; // get refernce to changing value
  free_space += value_ref.size();

  lru_node &node = pair -> second;
  lru_list.update_node_usage_status(node); //transfer node in the tail of list

  release_memory(value_size);
  free_space -= value_size;

  value_ref = value;
}


// bool SimpleLRU :: Put(const std :: string &key, const std :: string &value)
// {
//   size_t size = key.size() + value.size();
//
//   if (size > _max_size) //check if size is correct
//   {
//     return false;
//   }
//
//   if (!_lru_index.count(key)) //insert or set value
//   {
//     release_memory(size);
//     free_space -= size;
//
//     lru_node *new_elem = lru_list.add_in_end(key, value);
//     _lru_index.insert(std :: make_pair(std :: reference_wrapper<std :: string>(new_elem->key),
//                                        std :: reference_wrapper<lru_node>(*new_elem)));
//     return true;
//   }
//   else
//   {
//     size_t value_size = value.size();
//     std :: string &value_ref = pair -> second.get().value; // get refernce to changing value
//     free_space += value_ref.size();
//
//     release_memory(value_size);
//     free_space -= value_size;
//
//     value_ref = value;
//
//     return true;
//   }
// }


// See MapBasedGlobalLockImpl.h
bool SimpleLRU::PutIfAbsent(const std :: string &key, const std :: string &value)
{
  if (!_lru_index.count(key))
  {
    put_process(key, value);

    return true;
  }
  else
  {
    return false;
  }
}


// bool SimpleLRU::PutIfAbsent(const std :: string &key, const std :: string &value)
// {
//   if (!_lru_index.count(key))
//   {
//     release_memory(size);
//     free_space -= size;
//
//     lru_node *new_elem = lru_list.add_in_end(key, value);
//     _lru_index.insert(std :: make_pair(std :: reference_wrapper<std :: string>(new_elem->key),
//                                        std :: reference_wrapper<lru_node>(*new_elem)));
//     return true;
//   }
//   else
//     return false;
// }


// See MapBasedGlobalLockImpl.h
bool SimpleLRU :: Set(const std :: string &key, const std :: string &value)
{
  auto pair = _lru_index.find(key);

  if (pair != _lru_index.end())
  {
    set_process(pair, value);
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
    free_space += lru_list.delete_node(node); //delete from list

    return true;
  }
  else
    return false;
}


// See MapBasedGlobalLockImpl.h
bool SimpleLRU :: Get(const std :: string &key, std :: string &value)
{
  auto pair = _lru_index.find(key);

  if (pair != _lru_index.end())
  {
    lru_node &node = pair -> second;
    value = node.value; //recive value

    lru_list.update_node_usage_status(node); //transfer node in the tail of list

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


size_t SimpleLRU :: lru_node_list :: delete_node(lru_node &element)
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
  {
    element.next -> prev = element.prev;
    element.prev -> next = std :: move(element.next);
  }

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


void SimpleLRU :: lru_node_list :: update_node_usage_status(lru_node& node)
{
  if (node.next.get() != nullptr) //node is in place
  {
    if (_lru_head.get() == &node)
    {
      _lru_tail -> next = std :: move(_lru_head); //end pointers change
      _lru_head = std :: move(node.next);
      _lru_head -> prev = nullptr;
      node.prev = _lru_tail;
    }
    else
    {
      lru_node *prev = node.prev;

      _lru_tail -> next = std :: move(prev -> next); //end pointers change
      node.prev = _lru_tail;

      node.next -> prev = prev; //list gap treatment
      prev -> next = std :: move(node.next);
    }
    _lru_tail = _lru_tail -> next.get(); //suffles tail ptr
  }
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
