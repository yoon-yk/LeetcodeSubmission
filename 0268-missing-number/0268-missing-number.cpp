class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0, 1, 2, ... n
        int target = 0;
        for (int i=0; i<=nums.size(); i++) target += i;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return target-sum;
    }
};