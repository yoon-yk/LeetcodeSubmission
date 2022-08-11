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
                // cout << "sum : " << sum << " a : " << nums[aIdx] << " b : " << nums[bIdx] << " c : " << nums[cIdx] << endl;
                if (sum==0) {
                    ans.push_back({nums[aIdx], nums[bIdx], nums[cIdx]});
                    while (bIdx < nums.size()-1 && nums[bIdx] == nums[bIdx+1]) bIdx++;
                    while (cIdx > 0 && nums[cIdx] == nums[cIdx-1]) cIdx--;
                    bIdx++; cIdx--;
                }
                else if (sum < 0) {
                    while (bIdx < nums.size()-1 && nums[bIdx] == nums[bIdx+1]) bIdx++;
                    bIdx++;
                }
                else {
                    while (cIdx > 0 && nums[cIdx-1] == nums[cIdx]) cIdx--;
                    cIdx--;
                }
                
            }
            
            aIdx++;
            while (aIdx > 0 && aIdx < nums.size() && nums[aIdx-1] == nums[aIdx]) aIdx++;

        }
        
        return ans;

    }
};