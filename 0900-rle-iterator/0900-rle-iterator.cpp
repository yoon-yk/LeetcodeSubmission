class RLEIterator {
public:
    /*
    3 0 2
    3 3 5
    
    */    
    unsigned long cnt;
    vector<unsigned long> prefix;
    vector<unsigned long> val;
    
    RLEIterator(vector<int>& encoding) {
        cnt = 0;
        unsigned long sum = 0;
        for (int i=0; i<encoding.size(); i+= 2) {
            sum += encoding[i];
            prefix.push_back(sum);
        }
        for (int i=1; i<encoding.size(); i+= 2) {
            val.push_back(encoding[i]);
        }
    }
    
    int next(int n) {
        
        auto it = lower_bound(prefix.begin(), prefix.end(), n+cnt);
        cnt+=n;
        if (it == prefix.end()) return -1;
        return val[it-prefix.begin()];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */