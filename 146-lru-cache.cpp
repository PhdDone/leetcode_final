//maitain a double linked list, easy to insert and delete
//a hash map from key to iterator to the double linked list
//when get(), first search the hash map, get the iterator, insert the iterator to
//the begin of the double linked list and return the value
//when set(), first search the hash map, if not exist and reach the capacity, delete the last one
//in the doubled list. ALSO delete the key in the hashmap.
//then push the new key -> value to the begin of the double-list

class LRUCache{
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
  }
    
  int get(int key) {
    auto iter = cacheMap.find(key);
    if (iter == cacheMap.end()) return -1;
        
    cacheList.splice(cacheList.begin(), cacheList, iter->second);
    cacheMap[key] = cacheList.begin();
    return cacheMap[key]->val;
  }
    
  void set(int key, int value) {
    auto iter = cacheMap.find(key);
    if (iter == cacheMap.end()) {
      if (cacheMap.size() == capacity) {
	cacheMap.erase(cacheList.back().key); //remeber to also delete on map!!
	cacheList.pop_back();
      }
      cacheList.push_front(CacheNode(key, value));
      cacheMap[key] = cacheList.begin();
    }
    else {
      cacheMap[key]->val = value;
      cacheList.splice(cacheList.begin(), cacheList, iter->second);
      cacheMap[key] = cacheList.begin();
    }
  }
private:
  struct CacheNode {
    int key;
    int val;
    CacheNode(int k, int v) : key(k), val(v) {}
  };
  int capacity;
  list<CacheNode> cacheList;
  unordered_map<int, list<CacheNode>::iterator> cacheMap;
};
