class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        unordered_map<int, vector<int>> hashM; 
        for (int i=0; i<n; i++) hashM[nums[i]].push_back(i);
        
        for (int idx=0; idx<n; idx++) {
            if (hashM.count(target-nums[idx])) {
                for (int num : hashM[target-nums[idx]])
                    if (num!= idx)
                        return {idx, num};
            }
        }
        return {-1, -1};
    }
};