class Solution {
public:
    int maxWidth;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        maxWidth = shelfWidth;
        /**
        
        minimum possible height
        = as many books as possible in one shelf 
        .. screen fitting?
        
        1/23/4567
        12/345/67
        122
        ... DP!
        **/
        int n = books.size();
        vector<vector<int>> dp(n, vector<int>(shelfWidth+1, -1));
        return backtrack(books, 0, 0, 0, dp);
    }
    
    int backtrack(vector<vector<int>>& b, int idx, int width, int height, vector<vector<int>>& dp) {
        
        if (idx == b.size()) 
            return height;
        
        if (dp[idx][width] != -1) 
            return dp[idx][width];
        
        int curW = b[idx][0], curH = b[idx][1];
        
        // try next shelf
        int ans = height + backtrack(b, idx+1, curW, curH, dp);
        
        // push into curr shelf
        if (width + curW <= maxWidth) {
            ans = min(ans, backtrack(b, idx+1, width+curW, max(height, b[idx][1]), dp));
        }

        return dp[idx][width] = ans;
    }
    
    
};