class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets = {{}};
        
        int subsetSize = 0;
        
        for (int i=0; i<nums.size(); i++) {
            int startingIdx = (i>=1 && nums[i] == nums[i-1]) ? subsetSize : 0;
            subsetSize = subsets.size();
            for (int j = startingIdx; j<subsetSize; j++) {
                vector<int> curSubset = subsets[j];
                curSubset.push_back(nums[i]);
                subsets.push_back(curSubset);
            }
        }
        
        return subsets;
    }
};