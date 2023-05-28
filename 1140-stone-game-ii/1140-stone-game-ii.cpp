class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // a + a + x = sum(piles)
        // 2a + x = sum(piles)
        // 2a = sum(piles) - x
        // a = (sum(piles)-x)/2
        
        int n = piles.size();
        int sum = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n, vector<int> (2*n, -1));
        return (sum+solve(piles, 0, 1, dp))/2;
    }
    
    int solve(vector<int>& piles, int idx, int m, vector<vector<int>>& dp) {
        if (idx >= piles.size()) {
            return 0;
        }
        
        if (dp[idx][m] != -1) {
            return dp[idx][m];
        }
        
        int ans = INT_MIN, sum = 0;
        
        // 내가 여기서 얻을 수 있는 최대 선택
        // max(내가 이번에서 얻는 sum - 상대가 얻을 수 있는 최대 값)
        for (int i=0; i<2*m; ++i) {
            if (idx+i >= piles.size()) break;
            sum += piles[idx+i];
            ans = max(ans, sum - solve(piles, idx+i+1, max(i+1, m), dp));
        }
        return dp[idx][m] = ans;
    }
};