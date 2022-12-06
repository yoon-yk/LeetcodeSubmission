class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;
        int target = sum >> 1;
        if (*max_element(nums.begin(), nums.end()) > target) return false;
        
        int n = nums.size();
        vector<bool> prev(target+1, false), cur(target+1, false);
        
        prev[0] = true;
        for (int i=0; i<n; ++i) {
            for (int s=1; s<=target; ++s) {
                if (s-nums[i] >= 0 && prev[s-nums[i]])
                    cur[s] = true;
            }
            prev = cur;
        }
                
        return cur[target];
    }
};