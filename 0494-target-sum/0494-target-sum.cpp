class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> prev;
        unordered_map<int, int> curr;
        
        
        /*
          -5 -4 -3 -2 -1  0  1  2  3
        0        0  0  0  1  0  0  0
        1        0  0  1  1  1  0  0
        2        0  1  1  3  1  1  0
        3        1  2  5  5  5  2  1 
        4        3  
  
        
        
        */
        prev[0] = 1;
        for (int i=0; i<n; ++i) {
            curr.clear();
            for (int s = -sum; s<=sum; ++s) {
                curr[s] += prev[s-nums[i]];
                curr[s] += prev[s+nums[i]];
            }
            prev = curr;
        }
        
        return curr[target];
    }
};