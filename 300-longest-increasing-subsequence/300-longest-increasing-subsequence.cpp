class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        int LIS[nums.size()], globalMax = INT_MIN, curMax, tmp;
        LIS[nums.size()-1] = 1;
        
        for (int i = nums.size()-2; i >= 0; i--) {
            LIS[i] = 1;
            for (int j = i+1; j < nums.size(); j++) {
                tmp = (nums[j] > nums[i])? LIS[j] + 1 : 1; 
                LIS[i] = max(LIS[i], tmp);
            }
            globalMax = max(LIS[i], globalMax);
        }
        return globalMax;
    }
};
