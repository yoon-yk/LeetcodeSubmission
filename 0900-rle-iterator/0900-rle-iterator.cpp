class RLEIterator {
public:
    long long  curIdx;
    vector<long long> idx;
    vector<int> val;
    RLEIterator(vector<int>& encoding) {
        curIdx = 0;
        long long prefix = 0;
        for (int i=0; i<encoding.size(); i+=2) {
            if (encoding[i] == 0) continue;
            prefix += encoding[i];
            idx.push_back(prefix);
            val.push_back(encoding[i+1]);
        }
    }
    
    int next(int n) {
        curIdx+=n;
        auto it = lower_bound(idx.begin(), idx.end(), curIdx);
        if (it == idx.end()) return -1;
        return val[it-idx.begin()];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */