class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1, 0); // dp[curIdx] = maxCnt
        
        int curMax = 0;
        dp[0] = 1;
        
        int i, j;
        for (i=1; i<=n; i++) {
            int rowMax = 0;
            for (j=0; j<=i; j++) {
                int ans;
                if (j == 0) // 그 전 원소가 없을 때 
                    ans = 1;
                else if (j==i)
                    ans = rowMax;
                else if (nums[i-1] > nums[j-1]) // 그 전 원소보다 클 때 
                    ans = dp[j] + 1; // j가 cur 일 때의 최대값 
                else // 그 전 원소보다 작거나 같을 때 
                    ans = 1; // 그 전 원소 안넣는 걸로
                rowMax = max(rowMax, ans);
            }
            dp[j-1] = rowMax; 
            curMax = max(rowMax, curMax);
        }
        
        return curMax;
    }
};