class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // Two pointers
        
        // 1. sort 
        sort(nums.begin(), nums.end());
        
        int slow = 0, fast = 1, ans = 0;
        
        // 2. Two pointers
        while (fast < nums.size() && slow < nums.size()) {

            if (slow == fast || nums[fast]-nums[slow] < k)
                fast ++;
            else {
                if (nums[fast]-nums[slow] == k) {
                    ans ++; fast ++;
                    while (fast < nums.size() && nums[fast]==nums[fast-1]) {fast++;}
                }
                slow ++;
                while (slow < nums.size() && nums[slow]==nums[slow-1]) {slow++;}
                }
            }
        
        return ans;
    }
};