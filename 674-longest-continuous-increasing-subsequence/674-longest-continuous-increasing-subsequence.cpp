class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count, ret = INT_MIN, i=1;
        if (nums.size() < 1) return 0;
        if (nums.size() == 1) return 1;
        while (i<nums.size()) {
            count = 1;
            while ((i< nums.size()) && (nums[i-1] < nums[i])) {
                count++; i++;
            }
            printf("i=%d\n", i);
            ret = max(ret, count);
            i++;
        }
        return ret;
    }
};