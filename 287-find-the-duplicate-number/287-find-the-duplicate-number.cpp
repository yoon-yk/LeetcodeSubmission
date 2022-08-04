class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int start = nums[0];
        int slow = start, fast = start;
        
        // find the intersection 
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // find the cycle starting point
        slow = start;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};