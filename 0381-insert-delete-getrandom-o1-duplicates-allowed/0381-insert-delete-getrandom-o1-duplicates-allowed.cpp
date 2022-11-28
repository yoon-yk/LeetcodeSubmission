class RandomizedCollection {
public:
    
    vector<int> arr;
    unordered_map<int, priority_queue<int>> map;
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans = (!map.count(val) || map[val].size() == 0);
        arr.push_back(val);
        map[val].push(arr.size()-1);
        
        return ans;
    }
    
    bool remove(int val) {
        
        if (!map.count(val) || map[val].empty()) return false;
        int origIdx = map[val].top();
        int backVal = arr.back(), backIdx = map[backVal].top();
        
        if (origIdx != backIdx) {
            map[backVal].pop();
            arr[origIdx] = backVal;
            map[backVal].push(origIdx);            
        }
        
        map[val].pop();
        arr.pop_back();
        
        return true;
    }
    
    int getRandom() {
        int randIdx = random() % arr.size();
        return arr[randIdx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */