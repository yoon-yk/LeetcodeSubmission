class LRUCache {
public:
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> mp; // 
    list<pair<int, int>> l; 
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    void deleteLRC() {
        if (l.size() <= size ) return;
        int delKey = l.back().first;
        mp.erase(delKey);
        l.pop_back();
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        auto it = mp[key];
        int ans = (*it).second;
        l.emplace_front(*it);
        l.erase(it);
        mp[key] = l.begin();
        deleteLRC();
        return ans;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            auto it = mp[key];
            (*it).second = value;
            l.emplace_front(*it);
            l.erase(it);
        } else {
            l.emplace_front(pair(key, value));
        }
        mp[key] = l.begin();
        deleteLRC();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */