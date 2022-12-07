class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        /*
        2 3 -2 4
        2 3 -6 -24
        2 6 -2 4
        
        -2 -3 7
        -2 -3 -21
        -2  6 
        
        
        */
        int n = nums.size(), ans = nums[0], prevMaxChain, prevMinChain, minChain, maxChain;
        minChain = maxChain = nums[0];
        for (int i=1; i<n; ++i) {
            prevMaxChain = maxChain, prevMinChain = minChain;
            minChain = min(nums[i], min(prevMinChain * nums[i], prevMaxChain * nums[i]));
            maxChain = max(nums[i], max(prevMaxChain * nums[i], prevMinChain * nums[i]));
            ans = max(maxChain, ans);
        }
        
        return ans;
    }
};