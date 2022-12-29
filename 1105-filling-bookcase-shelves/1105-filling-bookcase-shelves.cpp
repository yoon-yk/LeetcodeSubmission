class Solution {
public:
    int maxW;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // 어쨌든 큰 애들은 우겨넣는게 최선, greedy는 안될걸?
        int n = books.size();
        maxW = shelfWidth;
        vector<vector<int>> dp(n+1, vector<int>(shelfWidth+1, -1));
        return backtrack(books, 0, 0, 0, dp);
    }
    
    int backtrack(vector<vector<int>>& books, int idx, int curW, int curH, vector<vector<int>>& dp) {
        
        if (idx == books.size()) 
            return curH;
        
        if (dp[idx][curW]!=-1) return dp[idx][curW];
        
        int bw = books[idx][0], bh = books[idx][1];
        
        int ans = backtrack(books, idx+1, bw, bh, dp) + curH;
        
        if (curW + bw <= maxW)
            ans = min(ans, backtrack(books, idx+1, curW+bw, max(curH, bh), dp));
        
        return dp[idx][curW] = ans;
    }
};