class LRUCache {
public:
    int cap;
    unordered_map <int, list<pair<int, int>>::iterator> iterMap; 
    list<pair<int, int>> cacheList;
        
    LRUCache(int capacity) : cap{capacity} {}
    
    int get(int key) {
        if (!iterMap.count(key)) return -1;
        cacheList.splice(cacheList.begin(), cacheList, iterMap[key]); // Move to the front
        return iterMap[key]->second; // Return the value of the key
    }
    
    void put(int key, int value) {
        if (iterMap.count(key)) // if exists
        {
            cacheList.splice(cacheList.begin(), cacheList, iterMap[key]); // Move to the front
            iterMap[key]->second = value; // Update the value of the key 
        }
        else {
            if (cacheList.size() >= cap) { // if the size exceeds the capacity
                int keyLRU = cacheList.back().first;
                cacheList.pop_back();
                iterMap.erase(keyLRU);
            }
            cacheList.emplace_front(key, value); // Move to the front
            iterMap[key] = cacheList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */