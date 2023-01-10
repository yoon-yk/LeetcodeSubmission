class Solution {
public:
    int nSlots;
    int maximumANDSum(vector<int>& nums, int numSlots) {
        // sort(nums.begin(), nums.end(), greater<int>());
        int singleSlots = 0, doubleSlots = 0;
        int maxSize = pow(2, numSlots+1);
        vector<vector<int>> dp(maxSize, vector<int>(maxSize, -1));
        nSlots = numSlots;
        return backtrack(0, nums, singleSlots, doubleSlots, dp);
    }
    
    int backtrack(int idx, vector<int>& nums, int singleSlots, int doubleSlots, vector<vector<int>>& dp) {
        
        if (idx == nums.size()) return 0;
        if (dp[singleSlots][doubleSlots] != -1) {
            return dp[singleSlots][doubleSlots];
        }

        int ans = 0;
        // for (int i=slots.size()-1; i>=0; --i) {
        for (int i=0; i<nSlots; ++i) {  

            if (doubleSlots & (1 << i)) continue;
            if (singleSlots & (1 << i)) { // has one elem
                ans = max(ans, (i+1 & nums[idx]) + backtrack(idx+1, nums, singleSlots, doubleSlots | (1 << i), dp));
            } else { // has no elem yet
                ans = max(ans, (i+1 & nums[idx]) + backtrack(idx+1, nums, singleSlots | (1 << i), doubleSlots, dp));
            }

        }
        return dp[singleSlots][doubleSlots] = ans;
    }
};