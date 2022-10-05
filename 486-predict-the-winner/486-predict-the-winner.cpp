class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int i=1; i<=n; i++) 
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        
        for (int size=0; size<n; size++) {
            for (int l=1; l+size <= n; l++) {
                int r = l+size;
                dp[l][r] = prefixSum[r] - prefixSum[l-1];
                if (l!=r)
                    dp[l][r] -= min (dp[l+1][r], dp[l][r-1]);
            }
        }
        
        for (int i=0; i<=n; i++){
            for (int j=0; j<=n; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        // 내가 더 큰 점수를 갖고 있다면 승리 
        return dp[1][n] >= ((float)prefixSum[n] / 2.0); 
    }
};
