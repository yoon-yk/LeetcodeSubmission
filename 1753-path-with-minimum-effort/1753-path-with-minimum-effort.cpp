class Solution {
public:
    vector<vector<int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    bool possible(int i, int j, int max, vector<vector<int>>& h,
    vector<vector<bool>>& vis) {
        
        if (i == h.size()-1 && j == h[0].size()-1) 
            return true;

        vis[i][j] = true;

        bool ans = false;
        for (auto & dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (min(ni, nj) < 0 || ni >= h.size() || nj >= h[0].size() || 
                vis[ni][nj] || abs(h[i][j]-h[ni][nj]) > max) continue;
            if (possible(ni, nj, max, h, vis)) return true;
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& h) {
        int lo = 0, hi = 1e6 + 1;
        // np np np p p p p 


        while (lo < hi) {
            vector<vector<bool>> vis(h.size(), vector<bool>(h[0].size(), false));
            vis[0][0] = true;

            int mi = lo + ((hi - lo) >> 1);
            if (possible(0, 0, mi, h, vis)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return lo;
    }
};