class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshNum = 0;
        queue<pair<int, int>> Q;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                freshNum += (grid[i][j] == 1);
                if (grid[i][j] == 2) {
                    Q.push({i, j});
                }
            }
        }
        
        int dir[] = {-1, 0, 1, 0, -1};
        int minutes = 0;
        int i, j;
        
        while (!Q.empty()) {
            int size = Q.size();
            while (size-- > 0) {
                auto top = Q.front(); Q.pop();
                i = top.first, j = top.second;                
                for (int d = 0; d < 4; d++) {
                    if (i+dir[d] < 0 || i+dir[d] >= grid.size() || j+dir[d+1] < 0 || j+dir[d+1] >= grid[0].size())
                        continue;
                    if (grid[i+dir[d]][j+dir[d+1]] == 1) {
                        freshNum--;
                        grid[i+dir[d]][j+dir[d+1]] = 2;
                        Q.push({i+dir[d], j+dir[d+1]});
                    }
                }
            }
            if (Q.empty()) break;
            minutes++;
        }
        
        if (freshNum == 0) return minutes;
        return -1;
        
    }
};