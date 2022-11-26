class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        /*
        0 1 2 3 4 5 6
        
        */
        
        while (lo < hi) {
            int mid = lo + ((hi-lo) >> 1);
            if (nums[mid] == target) return mid;
            else if (nums[lo] == target) return lo;
            else if (nums[hi] == target) return hi;
            
            if (nums[lo] > nums[hi]) {
                if (nums[mid] > nums[hi])
                    lo = mid+1;
                else hi = mid;
            } else {
                hi --;
            }
        }
        
        int origIdx = hi;
        
        if (nums[hi] == target) return hi;
        
        if (target <= nums[nums.size()-1]) 
            lo = origIdx, hi = nums.size()-1;
        else lo = 0, hi = origIdx-1;
        
        while (lo <= hi) {
            int mid = lo + ((hi-lo) >> 1);
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid+1;
            else hi = mid-1;
        }
            
        return -1;
    }
};