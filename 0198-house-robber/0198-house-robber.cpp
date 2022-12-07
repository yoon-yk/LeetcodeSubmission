class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int prevSec = nums[0], prevFirst = max(nums[0], nums[1]), cur = prevFirst;
        for (int i=2; i<n; i++) {
            cur = max(prevSec + nums[i], prevFirst);
            prevSec = prevFirst, prevFirst = cur;
        }
        return cur;
    }
};