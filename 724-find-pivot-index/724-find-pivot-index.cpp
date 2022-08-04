class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int leftSum = 0; 
        int rightSum = 0;
        
        for (int n:nums)
            rightSum += n;
        
        int ans = -1;
        for (int i=0; i<nums.size(); i++) {
            rightSum -= nums[i];
            if (leftSum == rightSum){
                ans = i;
                break;
            }
            leftSum += nums[i];
        }
        

        
        return ans;
        
    }
};