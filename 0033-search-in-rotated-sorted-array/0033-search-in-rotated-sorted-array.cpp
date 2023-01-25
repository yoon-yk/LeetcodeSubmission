class Solution {
public:
    int findPivot(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mi;
        while (lo <= hi) {
            mi = lo + ((hi-lo)>>1);
            if (mi>0 && nums[mi-1] > nums[mi]) return mi;
            if (nums[mi] < nums[hi]) hi = mi-1;
            else lo = mi+1;
        }
        return 0;
    }
    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) 
            return (nums[0] == target) ? 0 : -1;
        
        int piv = findPivot(nums);
        
        if (nums[piv] == target) return piv;
        
        int lo, hi, mi;
        if (target <= nums.back()) lo = piv+1, hi = nums.size()-1;
        else lo = 0, hi = piv-1;
            
        while (lo <= hi) {
            mi = lo + ((hi-lo)>>1);
            if (nums[mi] == target) return mi;
            if (nums[mi] < target) lo = mi+1;
            else hi = mi-1;
        }
        
        return -1;
    }
};