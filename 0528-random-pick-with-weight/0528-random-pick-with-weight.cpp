class Solution {
public:
    vector<int> prefix;
    
    /*
    1 4
    */
    Solution(vector<int>& w) {
        int sum = 0;
        for (auto & i : w) {
            sum += i;
            prefix.push_back(sum);
        }
    }
    
    int pickIndex() {
        int left = 0, right = prefix.back();
        float randVal = ((float)rand() / RAND_MAX) * right;
        int randIdx = lower_bound(prefix.begin(), prefix.end(), randVal) - prefix.begin(); 
        return randIdx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */