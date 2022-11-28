class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> map;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (map.count(val)) return false;
        arr.push_back(val);
        map[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!map.count(val)) return false;
        int origIdx = map[val];
        map[arr.back()] = origIdx;
        swap(arr[map[val]], arr.back());
        arr.pop_back();
        map.erase(val);
        return true;
    }
    
    /*
     0  1  2  3
    01 10 20 30
    
    */
    int getRandom() {
        int randIdx = random() % (arr.size());
        return arr[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */