class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ret = backtrack(0, n-1, piles, dp);
        
        return ret > 0;
    }
    
    int backtrack(int start, int end, vector<int>& piles, vector<vector<int>>& dp) {
        if (start > end) return 0;
        if (dp[start][end] != -1) return dp[start][end];
        
        int left = -backtrack(start+1, end, piles, dp) + piles[start];
        int right = -backtrack(start, end-1, piles, dp) + piles[end];

        return dp[start][end] = max(left, right);
    }
    
};