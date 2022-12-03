class DetectSquares {
public:
    
    unordered_map<int, unordered_map<int, int>> mp;
    
    DetectSquares() {}
    
    void add(vector<int> point) {
        ++mp[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        
        int curX = point[0], curY = point[1];
        int ans = 0;
        
        for (auto & [xv, yvs] : mp) {
            if (xv == curX) continue;
            
            for (auto & [yv, cnt] : yvs) {
                if (yv == curY || abs(yv-curY) != abs(xv-curX)) continue;
                
                ans += mp[xv][curY] * mp[curX][yv] * mp[xv][yv];
            }
        }
        
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */