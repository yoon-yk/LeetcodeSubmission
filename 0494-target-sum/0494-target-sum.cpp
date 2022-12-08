class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> prev((sum << 3) + 1, 0), curr((sum << 3) + 1, 0);
        /*
           0  1  2  3  4  5  6  7  8  9 10
          -5 -4 -3 -2 -1  0  1  2  3  4  5
        0        0  0  0  1  0  0  0
        1        0  0  1  1  1  0  0
        2        0  1  1  3  1  1  0
        3        1  2  5  5  5  2  1 
        4        3  
  
        
        
        */
        int base = sum * 2;
        prev[base] = 1;
        for (int i=0; i<n; ++i) {
            for (int s = base - sum; s <= base + sum; ++s) {
                curr[s] = 0;
                curr[s] += prev[s - nums[i]];
                curr[s] += prev[s + nums[i]];
            }
            prev = curr;
        }
        
        return curr[base + target];
    }
};