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
        
        
        int ans = nums[0];
        minArr[0] = maxArr[0] = nums[0];
        for (int i=1; i<n; i++) {
            minArr[i] = min(nums[i], min(maxArr[i-1]*nums[i], minArr[i-1]*nums[i]));
            maxArr[i] = max(nums[i], max(maxArr[i-1]*nums[i], minArr[i-1]*nums[i]));
            ans = max(maxArr[i], ans);
        }

        return ans;
    }
};