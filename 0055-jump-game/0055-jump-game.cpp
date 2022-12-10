class Solution {
public:
    
    /*
        <0 1 2 3 4>
        [2,3,1,1,4]
        [2,4,3,4,8]
        
        <0 1 2 3 4>
        [3,2,1,0,4]
        [3,3,3,3,8]
   
        <0 1 2 3 4>
        [3,1,1,1,4]
        [3,1,3,4,8]
        
        <0 1 2 3 4>
        [0,0,2,0,4]
        [0,1,3,3,8]
        
        <0 1 2>
        [0,0,2]
        [0,1,4]
  
        <0 1 2>
        [0,8,0]
        [0,9,0]
        
        
        
        */
    bool canJump(vector<int>& nums) {
        
        int curMax = 0;
        int n = nums.size();
        for (int i=0; i<n-1; ++i) {
            curMax = max(nums[i]+i, curMax);
            if (curMax <= i) return false;
        }
        return true;
    }

};