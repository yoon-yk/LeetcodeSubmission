class Solution {
public:
    bool isPeak(vector<int>& nums, int idx) {
        if (((idx-1 < 0) || nums[idx-1] < nums[idx]) && (idx+1 >= nums.size() || nums[idx+1] < nums[idx]))
            return true;
        return false;
    }
    
    bool isAscending(vector<int>& nums, int idx){
        return (idx-1 < 0 || nums[idx-1] < nums[idx]);
    }
    
    int findPeakElement(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = start + ((end-start) >> 1);
            if (isPeak(nums, mid)) return mid;
            if (isAscending(nums, mid)) start = mid + 1;
            else end = mid-1;
        }
        
        return start;
    }
};