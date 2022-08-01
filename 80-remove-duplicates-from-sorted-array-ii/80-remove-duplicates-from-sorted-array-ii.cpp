class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0, occur = 1;
        nums[left++] = nums[right++];
        while (right < nums.size()) {
            if (nums[right-1] == nums[right]) {
                if (++occur <= 2) 
                    nums[left++] = nums[right];   
            }
            else {
                occur = 1;
                nums[left++] = nums[right];
            }
            right++;
        }
        return left;
    }
};