class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int start = 0, end = 0;
        int idx = 0;
        
        while (end < nums.size()) {
            if (start == end) {
                nums[idx++] = nums[start];
                end ++;
            }
            else {
                if (nums[end-1] == nums[end]) {
                    end++;
                }
                else {
                    start = end;                    
                }
            }
        }
        return idx;
    }
};