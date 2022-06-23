class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int m = image.size(), n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        DFS(image, visited, sr, sc, image[sr][sc], color);
        
        return image;
    }
    
    void DFS(vector<vector<int>>& image, vector<vector<bool>>& visited, int sr, int sc, int origcolor, int color) {
        
        if (sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || visited[sr][sc] || image[sr][sc]!=origcolor) return;
        
        visited[sr][sc] = true;
        image[sr][sc] = color;
        DFS(image, visited, sr+1, sc, origcolor, color);
        DFS(image, visited, sr-1, sc, origcolor, color);
        DFS(image, visited, sr, sc+1, origcolor, color);
        DFS(image, visited, sr, sc-1, origcolor, color);
    }
};