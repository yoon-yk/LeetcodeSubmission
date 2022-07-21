class Solution {
public:
    
    /*
    0 1 2 3 4 5 
    0 1 3 4 5
    
    // edge cases
    1. very first elem
    2. very end elem
    3. rest
    4. single input
    */
    
    int missingNumber(vector<int>& nums) {
        int start = 0, end = nums.size()-1, mid;
        sort(nums.begin(), nums.end());
        
        // if(nums[end] == end) return end+1;
        while (start < end) {
            mid = (start + end + 1) >> 1;
            if (mid < nums[mid])
                end = mid - 1;
            else start = mid;
        }
        return (start==nums[start])? start+1 : start;
        
    }
};