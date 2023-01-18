class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> st; // val, loc
    RandomizedSet() {}
    
    bool insert(int val) {
        if (st.count(val)) return false;
        v.push_back(val);
        st[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if (!st.count(val)) return false;
        
        int valIdx = st[val]; 
        int lastV = v.back();
        st[lastV] = valIdx;
        v[valIdx] = lastV;
        v.pop_back();
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int ri = rand() % v.size(); // [0, n-1]
        return v[ri];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */