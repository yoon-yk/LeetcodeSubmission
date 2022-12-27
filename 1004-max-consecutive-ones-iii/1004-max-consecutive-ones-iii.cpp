class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCnt = 0, start = 0, end, ans = 0;
        for (end=0; end<nums.size(); ++end) {
            if (nums[end] == 0) {
                ++zeroCnt;
            }
            
            if (zeroCnt > k) {
                if (nums[start] == 0) --zeroCnt;
                ++start;
            }
            
        }
        return end-start;
    }
};