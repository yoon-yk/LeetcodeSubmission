class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 0, occur = 1;
        nums[left++] = nums[right++];
        while (right < nums.size()) {
            if (nums[right-1] == nums[right]) { // Duplicate
                if (++occur <= 2) 
                    nums[left++] = nums[right++];
                // else 
                    while (right < nums.size() && nums[right-1] == nums[right]) right++;
            }
            else { // Changing point
                occur = 1;
                nums[left++] = nums[right++];
            }
        }
        return left;
    }
};