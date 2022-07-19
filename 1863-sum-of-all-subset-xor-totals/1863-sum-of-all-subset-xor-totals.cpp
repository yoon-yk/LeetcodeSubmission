class Solution {
public:
    
    int helper(vector<int>& nums, int index, int currentXOR) {
        if (index == nums.size()){
            return currentXOR;
        }
        
        int include = helper(nums, index+1, currentXOR^nums[index]);
        int exclude = helper(nums, index+1, currentXOR);
        
        return include+exclude;
    }
    
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0);
    }
};