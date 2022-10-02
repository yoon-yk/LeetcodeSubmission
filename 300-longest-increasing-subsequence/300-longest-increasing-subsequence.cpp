class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // dp[curIdx][prevIdx] = curCnt
        
        int curMax = 0;
        for (int i=1; i<=n; i++) {
            int rowMax = 0;
            for (int j=0; j<=i; j++) {
                if (j == 0) // 그 전 원소가 없을 때 
                    dp[i][j] = 1;
                else if (j==i)
                    dp[i][j] = rowMax;
                else if (nums[i-1] > nums[j-1]) // 그 전 원소보다 클 때 
                    dp[i][j] = dp[j][j] + 1; // j가 cur 일 때의 최대값 
                else // 그 전 원소보다 작거나 같을 때 
                    dp[i][j] = 1; // 그 전 원소 안넣는 걸로
                rowMax = max(rowMax, dp[i][j]);
            }
            curMax = max(curMax, rowMax);
        }
        
        return curMax;
    }
};