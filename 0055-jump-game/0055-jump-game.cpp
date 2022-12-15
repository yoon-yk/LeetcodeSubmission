class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int curLv = 0, curEnd = 0, curMax = 0;
        for (int i=0; i<n-1; i++) {
            curMax = max(curMax, nums[i] + i);
            if (i == curEnd) {
                if (curMax <= curEnd) return false;
                curEnd = curMax;
                curLv ++;
            }
        }
        return true;
    }
};