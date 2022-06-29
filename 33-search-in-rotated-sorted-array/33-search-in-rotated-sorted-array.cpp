class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0) return -1;

        // 1. Find the index of the smallest value
        int start=0, end=size-1, mid;
        
        while (start<end){
            mid=(start+end)/2;
            if (nums[mid] > nums[end]) start = mid+1;
            else end = mid;
        }
        

        // 2. 
        if (nums[start] == target) return start;
        int rot = start;
        
        // 3. 
        start = 0, end = size-1;
        int realM; 
        
        while (start<=end) {
            mid = (start+end)/2;
            realM = (mid+rot)%size;
            if (nums[realM] == target) return realM;
            if (nums[realM] < target) start = mid+1;
            else end = mid-1;
        }
        
        return -1;
    }
};