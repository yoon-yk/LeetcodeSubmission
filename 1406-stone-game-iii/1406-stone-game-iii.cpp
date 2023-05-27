class Solution {
public:
    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        double sum = 0;
        for (int & p : piles) sum += p;
        double ret = solve(piles, 0, sum, true, dp);
        // cout << ret << " " << (sum/2) << endl;
        if (ret > (double)(sum/2)) {
            return "Alice";
        } else if (ret == (double)(sum/2)) {
            return "Tie";
        } return "Bob";
    }
    
    int solve(vector<int>& piles, int idx, int rest, bool turn, vector<vector<int>>& dp) {
        if (idx >= piles.size()) {
            return 0;
        }
        
        if (dp[idx][turn] != -1) {
            return dp[idx][turn];
        }
        
        int ans = INT_MIN, sum = 0;
        
        // 내가 여기서 얻을 수 있는 최대의 값
        // 내가 이번에서 얻는 최대 sum + (나머지 - 상대가 얻을 수 있는 최대 값)
        for (int i=0; i<3; ++i) {
            if (idx+i >= piles.size()) break;
            sum += piles[idx+i];
            rest -= piles[idx+i];
            ans = max(ans, sum + rest - solve(piles, idx+i+1, rest, !turn, dp));
        }
        
        return dp[idx][turn] = ans;
    }
};