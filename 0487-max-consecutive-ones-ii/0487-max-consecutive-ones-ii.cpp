class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zeroCnt = 0, start = 0, ans = 0, lastZero = 0;
        for (int end=0; end<nums.size(); ++end) {
            if (nums[end] == 0) {
                ++zeroCnt; 
                if (zeroCnt > 1) {
                    start = lastZero + 1;
                    zeroCnt = 1;
                }
                lastZero = end;
            } 
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};