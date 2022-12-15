class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        int curLv = 0, curEnd = 0, curMax = 0;
        for (int i=0; i<n; i++) {
            if (i == n-1) break;
            curMax = max(curMax, nums[i] + i);
            if (i == curEnd) {
                curEnd = curMax;
                curLv ++;
            }
        }
        return curLv;
    }
};