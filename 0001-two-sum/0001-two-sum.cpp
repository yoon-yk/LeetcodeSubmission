class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int, int> hashM;
        for (int i=0; i<n; i++) {
            int curN = nums[i];
            if (hashM.count(target-curN)) {
                return {i, hashM[target-curN]};
            } 
            hashM[curN] = i;
        }
        
        return {};
    }
};