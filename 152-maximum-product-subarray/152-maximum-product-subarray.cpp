class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int tmpMin, tmpMax, curMin = 1, curMax = 1, globalMax = INT_MIN;
        for (int i=0; i<nums.size(); i++) {
            tmpMin = curMin*nums[i];
            tmpMax = curMax*nums[i];
            curMax = max(tmpMin, max(curMax*nums[i], nums[i]));
            curMin = min(tmpMax, min(curMin*nums[i], nums[i]));
            globalMax = max(globalMax, curMax);
        }
        return globalMax;
    }
};


/*

-4 3 -1 5
==> -4, -4, -4
==> -12, 3, 3
==> -1, 12, 12

*/ 

