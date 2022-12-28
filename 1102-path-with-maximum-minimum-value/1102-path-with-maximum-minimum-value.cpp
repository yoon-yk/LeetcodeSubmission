class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int lo = 0, hi = min(grid[0][0], grid[n-1][m-1]);
        while (lo < hi) {
            int mi = (lo+hi+1) >> 1;
            if (exist(grid, mi)) lo = mi;
            else hi = mi-1;
        }
        return lo;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool isValid(vector<vector<int>>& grid, int i, int j){
        if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return false;
        return true;
    }
    bool exist(vector<vector<int>>& grid, int target){ 
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        Q.push({0, 0});
        int nR, nC;
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            if (cur.first == grid.size()-1 &&
                cur.second == grid[0].size()-1) return true;
            for (int d=0; d<4; ++d) {
                nR = cur.first + dir[d], nC = cur.second + dir[d+1];
                if (isValid(grid, nR, nC) && !visited[nR][nC] && 
                   grid[nR][nC] >= target) {
                    Q.push({nR, nC});
                    visited[nR][nC] = true;
                }
            
            }
        }
        
        return false;
    }
};