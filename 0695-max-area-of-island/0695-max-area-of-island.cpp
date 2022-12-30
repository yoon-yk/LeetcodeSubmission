class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};

    void printGrid(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();

        cout << endl;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (grid[i][j] != 1)  continue;
                ans = max(ans, bfs(grid, i, j));
            }
        }
        return ans;
    }
    int bfs(vector<vector<int>>& grid, int r, int c) {
        int ans = 0, ni, nj;
        queue<pair<int, int>>Q;
        Q.push({r, c});
        grid[r][c] = 9;
        while (!Q.empty()) {
            auto [i, j] = Q.front(); Q.pop();
            ++ans;
            
            for (int d=0; d<4; ++d) {
                ni = i+dir[d], nj = j+dir[d+1];
                if (ni<0 || nj<0 || ni>=grid.size() || nj>=grid[0].size() || grid[ni][nj]!=1) 
                    continue;
                Q.push({ni, nj});
                grid[ni][nj] = 9;
            }
        }
        return ans;
    }
};