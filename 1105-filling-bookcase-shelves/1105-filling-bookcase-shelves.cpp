class Solution {
public:
    int maxWidth;
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        maxWidth = shelfWidth;
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth+1, -1));
        return backtrack(books, 0, 0, 0, dp);
    }
    
    int backtrack(vector<vector<int>>& books, int idx, int curW, int curH, vector<vector<int>>& dp) {
        if (idx == books.size()) 
            return curH;
        if (dp[idx][curW] != -1)
            return dp[idx][curW];
        
        int include = INT_MAX, exclude;
        if (curW + books[idx][0] <= maxWidth) 
            include = backtrack(books, idx+1, curW+books[idx][0], max(curH, books[idx][1]), dp);
        exclude = curH + backtrack(books, idx+1, books[idx][0], books[idx][1], dp);
        
        return dp[idx][curW] = min(include, exclude);
    }
};