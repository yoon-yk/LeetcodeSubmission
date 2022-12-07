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
        int n = nums.size();
        vector<int> minArr(n, 1), maxArr(n, 1);
        minArr[0] = maxArr[0] = nums[0];
        for (int i=1; i<n; ++i) {
            minArr[i] = min(nums[i], min(minArr[i-1] * nums[i], maxArr[i-1] * nums[i]));
            maxArr[i] = max(nums[i], max(maxArr[i-1] * nums[i], minArr[i-1] * nums[i]));
        }
        
        return *max_element(maxArr.begin(), maxArr.end());
    }
};