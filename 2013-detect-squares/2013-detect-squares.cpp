class DetectSquares {
public:
    int n = 1005;
    vector<vector<int>> mp;
    vector<pair<int, int>> pool;
    
    DetectSquares() {
        mp.resize(n, vector<int>(n, 0));
    }
    
    void add(vector<int> point) {
        if (mp[point[0]][point[1]] == 0) pool.push_back({point[0], point[1]});
        ++mp[point[0]][point[1]];
    }
    
    int count(vector<int> point) {
        
        int ans = 0;
        int x = point[0], y = point[1];
        
        int i, j;
        for (auto & [i, j] : pool) {
            if (x!=i && y!=j && abs(x-i) == abs(y-j)) 
                ans += mp[i][j] * mp[i][y] * mp[x][j];
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