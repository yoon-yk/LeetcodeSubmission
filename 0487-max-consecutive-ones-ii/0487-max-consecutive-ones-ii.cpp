class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int oneCnt = 0, zeroCnt = 0, start = 0, ans = 0;
        for (int end=0; end<nums.size(); ++end) {
            if (nums[end] == 0) ++zeroCnt;
            else ++oneCnt;
            
            while (zeroCnt > 1) {
                (nums[start] == 0) ? --zeroCnt : --oneCnt;
                ++start;
            }
            
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};