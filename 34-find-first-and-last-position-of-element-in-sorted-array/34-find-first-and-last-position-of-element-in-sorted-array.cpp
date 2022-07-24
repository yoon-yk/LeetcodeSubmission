class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans; 
        if (nums.size() < 1) return {-1, -1};
        
        int firstPos, lastPos;
        
        int start = 0, end = nums.size()-1, mid;
        
        while (start < end) {
            mid = start + ((end-start) >> 1);
            if (nums[mid] < target)
                start = mid + 1;
            else end = mid;
        }
        
        if (nums[start]!=target) return {-1, -1};
        
        firstPos = start, end = nums.size()-1;
        
        while (start < end) {
            mid = start + ((end-start+1) >> 1);
            if (target < nums[mid])
                end = mid-1;
            else start = mid;
        }
        
        lastPos = start;
        
        return {firstPos, lastPos};
    }
};