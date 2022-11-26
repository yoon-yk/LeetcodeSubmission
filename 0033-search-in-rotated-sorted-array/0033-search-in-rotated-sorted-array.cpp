class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;

        while (lo < hi) {
          int mid = lo + ((hi-lo) >> 1);
          if (nums[mid] > nums[hi]) 
            lo = mid + 1;
          else 
            hi = mid;
        }
        
        int origIdx = hi;
        lo = 0, hi = nums.size()-1;
        int n = nums.size();
        while (lo <= hi) {
            int mid = lo + ((hi-lo) >> 1);
            int sortedMid = (origIdx + mid) % n;

            if (nums[sortedMid] == target) return sortedMid;
            else if (nums[sortedMid] < target) lo = mid+1;
            else hi = mid-1;
        }
            
        return -1;
    }
};