class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        sum = sum >> 1;
        if (*max_element(nums.begin(), nums.end()) > sum) return false;
        
        int n = nums.size();
        
        vector<int> cur(sum+1, 0), prev(sum+1, 0);
        prev[0] = cur[0] = 1;
        
        for (int i=0; i<n; ++i) {
            for (int s=0; s<=sum; ++s)
                if (s-nums[i] >= 0) cur[s] |= prev[s-nums[i]];
            prev = cur;
        }
        
        return cur[sum];
    }
};