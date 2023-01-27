class Solution {
public:
    int mod = 1e9 + 7;
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum >> 1;
        
        return subarraySumEqualKExist(nums, target);
    }
    
    bool subarraySumEqualKExist(vector<int>& nums, int target) {
        
        vector<int> prev(target+1, 0), now(target+1);
        
        prev[0] = 1;
        for (int i=1; i<=nums.size(); ++i) {
            if (nums[i-1] > target) continue;
            for (int s=0; s<=target; ++s) {
                now[s] = prev[s];
                if (s-nums[i-1] >= 0) 
                    now[s] = (prev[s-nums[i-1]] + now[s]) % mod;
            }
            prev.swap(now);
        }
        
        
        return now[target];
    }
};