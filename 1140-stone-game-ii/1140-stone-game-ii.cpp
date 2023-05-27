class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2*n, vector<int>(2, -1)));
        int rest = 0;
        for (int & p : piles) rest += p;
        return solve(piles, 0, 1, rest, true, dp);
    }
    
    int solve(vector<int>& piles, int idx, int m, int rest, bool turn, vector<vector<vector<int>>>& dp) {
        if (idx >= piles.size()) {
            return 0;
        }
        
        if (dp[idx][m][turn] != -1) {
            return dp[idx][m][turn];
        }
        
        int ans = 0, sum = 0;
        
        // 내가 여기서 얻을 수 있는 최대의 값
        // 내가 이번에서 얻는 최대 sum + (나머지 - 상대가 얻을 수 있는 최대 값)
        for (int i=0; i<2*m; ++i) {
            if (idx+i >= piles.size()) break;
            sum += piles[idx+i];
            rest -= piles[idx+i];
            ans = max(ans, sum + rest - solve(piles, idx+i+1, max(i+1, m), rest, !turn, dp));
        }
        return dp[idx][m][turn] = ans;
    }
};