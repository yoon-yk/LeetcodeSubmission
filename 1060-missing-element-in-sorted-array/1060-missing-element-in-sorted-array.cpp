class Solution {
public:
    
    int missing (int idx, vector<int>& nums) {
        return nums[idx] - nums[0] - idx;
    }
    
    int missingElement(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if (k > missing(n-1, nums))
            return nums[n-1] - missing(n-1, nums) + k;
        
        int left = 0, right = n-1, pivot;
        
        while (left < right) {
            pivot = left + ((right-left) >> 1);
            if (missing (pivot, nums) < k) left = pivot + 1;
            else right = pivot;
        }
        
        return nums[left-1] - missing(left-1, nums) + k;
    }
};