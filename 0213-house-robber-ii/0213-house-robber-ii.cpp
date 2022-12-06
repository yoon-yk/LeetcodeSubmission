class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if (n==1) return nums[0];
        
        return max(rob_simple(nums, 0, n-1), rob_simple(nums, 1, n));
    }
    
    int rob_simple(vector<int>& nums, int start, int end) {
        
        if (end-start+1 == 2) return nums[start];

        int prev_2 = 0, prev_1 = 0;
        for (int i=start; i<end; i++) {
            int curChoice = max(prev_2 + nums[i], prev_1);
            prev_2 = prev_1;
            prev_1 = curChoice;
        }
        
        return max(prev_2, prev_1);
    }
};