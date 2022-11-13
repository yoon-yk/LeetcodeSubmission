class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n, 0);
        int leftSum = 1, rightSum = 1;
        for (int i=0; i<n; i++) {
            ans[i] = leftSum;
            leftSum *= nums[i];
        }
        
        for (int i=n-1; i>=0; i--) {
            ans[i] *= rightSum;
            rightSum *= nums[i];
        }
        
        return ans;
        
    }
};