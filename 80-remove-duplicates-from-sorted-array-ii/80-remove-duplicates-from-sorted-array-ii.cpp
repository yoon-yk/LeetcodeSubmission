class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0;
        nums[left++] = nums[right++];
        while (right < nums.size()) {
            if (nums[right-1] == nums[right]) { // Duplicate
                nums[left++] = nums[right++];
                while (right < nums.size() && nums[right-1] == nums[right]) right++;
            }
            else { // Changing point
                nums[left++] = nums[right++];
            }
        }
        return left;
    }
};