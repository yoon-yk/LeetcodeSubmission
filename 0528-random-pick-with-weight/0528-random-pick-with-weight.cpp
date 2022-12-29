class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        int prefixS = 0;
        for (int & ww : w) {
            prefixS += ww;
            prefix.push_back(prefixS);
        }
    }
    
    int pickIndex() {
        int random = 1 + (rand() % (prefix.back()));
        auto it = lower_bound(prefix.begin(), prefix.end(), random);
        return it - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */