class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        unordered_map<int, unordered_set<int>> mp;
        int n = points.size(); 
 
        int minArea = INT_MAX;
        for (int i=0; i<n; i++) {
            int cX = points[i][0], cY = points[i][1];
                        mp[cX].insert(cY);

            for (auto &[x, ys] : mp) { // diagonal points
                
                if (x == cX || ys.size() < 2) continue;
                for (auto & y : ys) {
                    // x, y
                    if (y == cY) continue;
                    if (mp[cX].count(y) && mp[x].count(cY)) {
                        minArea = min(minArea, abs((cX-x) * (cY-y)));
                    }
                } 
            }
        }
        
        return minArea == INT_MAX ? 0 : minArea;
        
    }
};