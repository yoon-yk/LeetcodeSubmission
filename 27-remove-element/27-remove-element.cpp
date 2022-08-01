class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, ptr = 0;
        while (ptr < nums.size()) {
            // keep valid elems in the left side 
            if (nums[ptr] != val){
                // if ptr encounters not a target value, swap it with the left val
                swap(nums[left], nums[ptr]);
                left++;
            }
            ptr++;
        }
        return left;  
    }
};