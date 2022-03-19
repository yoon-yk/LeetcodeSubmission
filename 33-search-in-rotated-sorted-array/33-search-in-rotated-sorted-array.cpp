class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0 ) return -1;
        if (nums.size() == 1 ) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        
        int mid, left = 0, right = nums.size()-1;
        while (left < right) {
            mid = left + (right-left)/2; //*****
            if (nums[mid] > nums[right])
                left = mid+1;
            else right = mid;
        }

        int start = left; // beginning of sorted array
        left = 0; right = nums.size()-1; 
        if (target <= nums[right] && target >= nums[start]) left = start;
        else right = start-1;
        
        while (left <= right) { // left <= right!!!!!!!!
            mid = left + (right-left)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        
        return -1;
    }
};