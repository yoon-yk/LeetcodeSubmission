class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(sr, sc, image[sr][sc], color, image);
        return image;
    }
    
    void dfs(int i, int j, int srcC, int desC, vector<vector<int>>& image) {
        if (i < 0 || j < 0 || i >= image.size() || j >= image[0].size() ||
            image[i][j] != srcC || image[i][j] == desC)
            return;
        
        image[i][j] = desC;
        
        for (int d=0; d<4; d++)
            dfs(i+dir[d], j+dir[d+1], srcC, desC, image);
        
    }
};