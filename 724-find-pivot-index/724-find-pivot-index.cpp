class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> leftPrefix (nums.size()+1, 0);
        vector<int> rightPrefix (nums.size()+1, 0);
        
        // left
        for (int i=0; i<nums.size(); i++)
            leftPrefix[i+1] = leftPrefix[i]+nums[i];
        
        // right
        for (int i=nums.size()-1; i >= 0; i--)
            rightPrefix[i] = rightPrefix[i+1]+nums[i];

        int ans = -1;
        for (int i=0; i<nums.size(); i++)
            if (leftPrefix[i] == rightPrefix[i+1]){
                ans = i;
                break;
            }
        
        return ans;
        
    }
};