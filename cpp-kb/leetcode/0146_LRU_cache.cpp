#include "Problems.h"
#include <unordered_map>
#include <list>


using namespace std;

// https://leetcode.com/problems/lru-cache/?envType=problem-list-v2&envId=rab78cw1

class LRUCache {
    int size = {0};
    list<pair<int,int>> nodes;
    unordered_map<int, list<pair<int,int>>::iterator> nodes_map;
public:
    LRUCache(int capacity): size(capacity) {
        
    }
    
    int get(int key) {
        auto it = nodes_map.find(key);
        if(it == nodes_map.end())
            return -1;
        auto value = it->second->second; 
        nodes.erase(it->second);
        nodes.push_front({key, value});
        nodes_map[key] = begin(nodes);
        return value;
    }
    
    void put(int key, int value) {
        auto it = nodes_map.find(key);
        if(it != nodes_map.end())
        {
            nodes.erase(it->second);
        }
        nodes.push_front({key, value});
        nodes_map[key] = begin(nodes);
        if(nodes.size() > size)
        {
            auto rm = nodes.back();
            nodes_map.erase(rm.first);
            nodes.pop_back();
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    assert(1 == lRUCache.get(1));    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    assert(-1 == lRUCache.get(2));    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    assert(-1 == lRUCache.get(1));    // return -1 (not found)
    assert( 3 == lRUCache.get(3));    // return 3
    assert( 4 == lRUCache.get(4));    // return 4
    return 0;
}
