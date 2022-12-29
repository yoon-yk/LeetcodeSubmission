class DetectSquares {
public:
    vector<vector<int>> mp;
    DetectSquares() {
        mp.resize(1005, vector<int>(1005, 0));
    }
    
    void add(vector<int> point) {
        ++mp[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        
        int ans = 0;
        int x = point[0], y = point[1];
        for (int i=1; i<=1000; ++i) {
            if (x+i <= 1000) {
                if (y+i <= 1000) ans += mp[x+i][y+i] * mp[x+i][y] * mp[x][y+i];
                if (y-i >= 0) ans += mp[x+i][y-i] * mp[x+i][y] * mp[x][y-i];
            }
            if (x-i >= 0) {
                if (y-i >= 0) ans += mp[x-i][y-i] * mp[x-i][y] * mp[x][y-i];
                if (y+i <= 1000) ans += mp[x-i][y+i] * mp[x-i][y] * mp[x][y+i];
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