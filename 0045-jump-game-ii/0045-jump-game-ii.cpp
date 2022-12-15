class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        2,3,1,1,4
        ---------
        0 1 2 3 4
        2 4 3 4 8
        
        */
        int n = nums.size();
        int idx = 0;
        int nextMax = 0, cnt=0, curEnd = 0, maxReach = 0;
        while (nextMax < n-1) {
            for (; idx<=nextMax; idx++) 
                maxReach = max(idx + nums[idx], maxReach);
            nextMax = maxReach;
            cnt++;
        }
        return cnt;
    }
};