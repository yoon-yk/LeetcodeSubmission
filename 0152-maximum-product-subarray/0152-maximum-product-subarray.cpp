class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> maxArr(n, 1), minArr(n, 1);
        
        /*
             2,  3, -2,  4, -2,  0, -1
        min  2   3  -6 -24  -2 가 아니라 -8
        max 
        */
        
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