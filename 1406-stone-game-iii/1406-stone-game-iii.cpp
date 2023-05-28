class Solution {
public:
    string stoneGameIII(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n, -1);
        double ret = solve(piles, 0, dp);
        // cout << ret << " " << (sum/2) << endl;
        if (ret > 0) {
            return "Alice";
        } else if (ret == 0) {
            return "Tie";
        } return "Bob";
    }
    
    int solve(vector<int>& piles, int idx, vector<int>& dp) {
        if (idx >= piles.size()) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int ans = INT_MIN, sum = 0;
        
        // 내가 여기서 얻을 수 있는 최대 선택
        // max(내가 이번에서 얻는 sum - 상대가 얻을 수 있는 최대 값)
        for (int i=0; i<3; ++i) {
            if (idx+i >= piles.size()) break;
            sum += piles[idx+i];
            ans = max(ans, sum - solve(piles, idx+i+1, dp));
        }
        return dp[idx] = ans;
    }
};