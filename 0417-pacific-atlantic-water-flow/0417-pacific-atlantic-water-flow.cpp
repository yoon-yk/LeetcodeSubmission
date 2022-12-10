class Solution {
public:
    #define Pacific 0
    #define Atlantic 1
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        
        vector<vector<int>> visited(r, vector<int>(c, 0));
        
        // first col & last col
        for (int i=0; i<r; ++i) {
            dfs(i, 0, Pacific, INT_MIN, heights, visited);// first col : pacific
            dfs(i, c-1, Atlantic, INT_MIN, heights, visited);// last col : atlantic
        }
        
        // first row & last row
        for (int j=0; j<c; ++j) {
            dfs(0, j, Pacific, INT_MIN, heights, visited);// first row : pacific
            dfs(r-1, j, Atlantic, INT_MIN, heights, visited);// last row : atlantic          
        }
        
        vector<vector<int>> ans;
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (visited[i][j] == 3) 
                    ans.push_back({i, j});
            }
        }
        
        return ans;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    void dfs(int i, int j, int ocean, int curVal, vector<vector<int>>& heights, vector<vector<int>>& visited) {
        if (i<0 || i>=visited.size() || j<0 || j>=visited[0].size() || 
            (visited[i][j] & (1 << ocean)) || curVal > heights[i][j]) return;
        
        visited[i][j] |= (1 << ocean);

        int newI, newJ;
        for (int d=0; d<4; ++d) {
            newI = i+dir[d], newJ = j+dir[d+1];
            dfs(newI, newJ, ocean, heights[i][j], heights, visited);
        }
        
    }
    
    
};