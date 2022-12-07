class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(rob(nums, 0, n-1), rob(nums, 1, n));
    }
    
    int rob(vector<int>& nums, int start, int end) {
        if (end-start == 1) return nums[start];
        
        int prevSec = 0, prevFirst = 0, cur = prevFirst;
        
        for (int i=start; i<end; i++) {
            cur = max(prevSec + nums[i], prevFirst);
            prevSec = prevFirst, prevFirst = cur;
        }
        return cur;
    }
};