class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        vector<vector<int>> ans;
        
        //1. sort
        sort(nums.begin(), nums.end());
        
        //2. two pointers (skip the duplicates)
        // a + b + c = 0
        // --> 'a' should be a negavtive num; at least one elem should be negative
        // --> c should be starting from the bigger num; 
        
        int aIdx = 0;
        for (; aIdx<nums.size()-2;) {
            if (nums[aIdx] > 0) break;
            
            int bIdx = aIdx+1, cIdx = nums.size()-1;
            
            while (bIdx < cIdx) {
                int sum = nums[aIdx]+nums[bIdx]+nums[cIdx];
                if (sum==0) {
                    ans.push_back({nums[aIdx], nums[bIdx], nums[cIdx]});
                    bIdx = upper_bound(nums.begin(), nums.end(), nums[bIdx]) - nums.begin();
                    cIdx = lower_bound(nums.begin(), nums.end(), nums[cIdx]) - nums.begin();
                    cIdx--;
                }
                else if (sum < 0) {
                    bIdx++;
                }
                else {
                    cIdx--;
                }
                
            }
            aIdx = upper_bound(nums.begin(), nums.end(), nums[aIdx]) - nums.begin();
        }
        
        return ans;

    }
};