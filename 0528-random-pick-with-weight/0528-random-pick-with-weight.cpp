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
        int randVal = rand() % (right-left) + 1;
        int randIdx = lower_bound(prefix.begin(), prefix.end(), randVal) - prefix.begin(); 
        return randIdx;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */