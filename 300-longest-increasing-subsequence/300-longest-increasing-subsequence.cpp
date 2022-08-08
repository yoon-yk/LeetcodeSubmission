class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
         dp
         
         10 |  9 |  2 |  5 |  3 |  7 | 101 |  18 
          1    1    1    2    2    3     4     4
          
        dp[i] = max(dp[c] + 1, 1) (c < i, dp[c] < dp[i])
          
        */
        
        int size = nums.size();
        vector<int> dp(size, 1);
        int maxCnt = 1;
        
        for (int i=0; i<size; i++) {
            for (int j=i+1; j<size; j++) {
                if (nums[j] > nums[i]) {
                    dp[j] = max(dp[j], dp[i]+1);
                    maxCnt = max(maxCnt, dp[j]);
                }
            }
        }
        
        return maxCnt;
        
    }
};