class RandomizedSet {
public:
    list<int> li;
    unordered_map<int, list<int>::iterator> m;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.count(val)) return false;
        li.push_back(val);
        m[val] = li.end();
        return true;
    }
    
    bool remove(int val) {
        if (!m.count(val)) return false;
        li.remove(val);
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        float rand = (float) random() / RAND_MAX;
        float randIdx = floor(rand * (li.size()));
        // cout << rand << " " << randIdx << endl;
        int cnt = 0;
        
        for (auto &l : li) {
            if (cnt++ == randIdx)
                return l;
        }
        
        return -1;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */