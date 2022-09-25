class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) sum+= nums[i];
        if (sum % 2) return false;
        
        vector<bool> curr(sum+1, false), prev(sum+1, false);
        prev[0] = true;
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<=sum; j++) {
                if (prev[j]) {
                    curr[j] = true;
                    if (j+nums[i] <= sum) 
                        curr[j+nums[i]] = true;
                }
            }
            prev.swap(curr);
        }

        return curr[sum >> 1];
    }
};