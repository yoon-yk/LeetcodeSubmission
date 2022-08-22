class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int origColor, int color) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc]!=origColor || image[sr][sc] == color) {
            return;
        }
        
        image[sr][sc] = color;
        
        dfs(image, sr+1, sc, origColor, color);
        dfs(image, sr-1, sc, origColor, color);
        dfs(image, sr, sc+1, origColor, color);
        dfs(image, sr, sc-1, origColor, color);
    }
};