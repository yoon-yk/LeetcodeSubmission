class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0, r, c;
        int rlim = grid.size(), clim = grid[0].size();
        stack<pair<int, int>> st;
        
        for (int i=0; i<rlim; i++) {
            for (int j=0; j<clim; j++) {
                if (grid[i][j] != '1') continue;
                
                cnt ++;
                r = i, c = j;
                st.push({r, c});
                
                while (!st.empty()) {
                    auto cur = st.top(); st.pop();
                    grid[cur.first][cur.second] = '0';
                    
                    for (int d = 0; d < 4; d++)
                        if ((cur.first+dir[d] >= 0) && (cur.first+dir[d] < rlim) && 
                            (cur.second+dir[d+1] >= 0) && (cur.second+dir[d+1] < clim) && grid[cur.first+dir[d]][cur.second+dir[d+1]] == '1')
                            st.push({cur.first+dir[d], cur.second+dir[d+1]});
                }
                
            }
        }
        
        return cnt;
    }
};