class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, ps = 0, start = 0;
        for (int end = 0; end<n; ++end) {
            ps += nums[end];
            while (start <= end && ps > k) {
                ps -= nums[start];
                ++start;
            }
            ans += end-start;
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMostK(nums, goal) - atMostK(nums, goal-1);
    }
};