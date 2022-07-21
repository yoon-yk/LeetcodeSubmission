class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() < 1) return -1;
        
        int start = 0, end = nums.size()-1, mid;
        while (start < end) {
            mid = start + (end-start+1)/2;
            if (target == nums[mid]) return mid;
            
            if (target < nums[mid]) 
                end = mid-1;
            else 
                start = mid;
        }
        return nums[start]==target ? start : -1;
    }
};