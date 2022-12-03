class LRUCache {
public:
    using lit = list<pair<int, int>>::iterator;
    unordered_map<int, lit> mp;
    list<pair<int, int>> l;
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        
        if (!mp.count(key)) 
            return -1;
        
        l.splice(l.begin(), l, mp[key]);
        mp[key] = l.begin();
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (!mp.count(key))
            l.push_front({key, value});
        else {
            l.splice(l.begin(), l, mp[key]);
            l.front().second = value;
        }
        mp[key] = l.begin();
        
        if (l.size() > cap) {
            int delKey = l.back().first;
            l.pop_back();
            mp.erase(delKey);
        }
 
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */