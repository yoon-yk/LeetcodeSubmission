class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int start = 0;
        int slow = start, fast = start;
        
        // find the intersection 
        while (1) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        
        // find the cycle starting point
        slow = start;
        while (1) {
            slow = nums[slow];
            fast = nums[fast];
            if (slow == fast) break;  
        }

        return slow;
    }
};