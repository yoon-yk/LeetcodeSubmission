class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        unordered_map<int, int> hashM; 
        
        for (int idx=0; idx<n; idx++) {
            if (hashM.count(target-nums[idx])) {
                return {idx, hashM[target-nums[idx]]};
            }
            hashM[nums[idx]] = idx;
        }
        return {-1, -1};
    }
};