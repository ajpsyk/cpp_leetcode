#include <unordered_map>
#include <list>

class LRUCache {
private:
    struct CacheNode
    {
        int key;
        int val;
        CacheNode(int k, int v) : key(k), val(v) {}
    };

    int capacity;
    std::unordered_map<int, std::list<CacheNode>::iterator> map;
    std::list<CacheNode> list;

public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) return -1;

        list.splice(list.begin(), list, it->second);

        return it->second->val;
    }
    
    void put(int key, int value) {

        auto it = map.find(key);
        if (it != map.end())
        {
            it->second->val = value;
            list.splice(list.begin(), list, it->second);
            return;
        }
    
        if (map.size() == capacity)
        {
            map.erase(list.back().key);
            list.pop_back();
        }

        list.push_front(CacheNode(key, value));
        map[key] = list.begin();
    }

};