class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        int curMinChain, curMaxChain, temp, ans;
        curMinChain = curMaxChain = ans = nums[0];
        for (int i=1; i<n; i++) {
            temp = curMaxChain;
            curMaxChain = max(nums[i], max(curMaxChain*nums[i], curMinChain*nums[i]));
            curMinChain = min(nums[i], min(temp*nums[i], curMinChain*nums[i]));
            ans = max(curMaxChain, ans);
        }

        return ans;
    }
};