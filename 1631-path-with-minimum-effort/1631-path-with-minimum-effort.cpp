class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        /*
        ur ur ur r r r 
        */
        int lo = 0, hi = 1000000, mi;
        int ans = INT_MAX;
        while (lo <= hi) {
            mi = lo + ((hi-lo) >> 1);
            // cout << mi << " ";
            if (reacheable(heights, mi)) {
                // cout << "r" << endl;
                hi = mi-1;
                ans = min(mi, ans);
            } else {
                // cout << "ur" << endl;
                lo = mi+1;
            }
        }
        return ans;
    }
    
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool valid(int i, int j, vector<vector<int>>& heights) {
        if (i < 0 || j < 0 || i>= heights.size() || j >= heights[0].size()) return false;
        return true;
    } 
    
    bool reacheable(vector<vector<int>>& h, int limit) {
        
        int m = h.size(), n = h[0].size();
        queue<pair<int, int>> Q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        Q.push({0, 0});
        visited[0][0] = true;
        int nr, nc;
        while (!Q.empty()) {
            auto [cr, cc] = Q.front(); Q.pop();
            if (cr == m-1 && cc == n-1) return true;
            
            for (auto& [r, c] : dir) {
                nr = cr + r, nc = cc+ c;
                if (valid(nr, nc, h) && !visited[nr][nc] && abs(h[nr][nc]-h[cr][cc]) <= limit) {
                    Q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return false;
    }
    

};