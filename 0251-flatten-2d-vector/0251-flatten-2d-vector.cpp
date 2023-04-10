class Vector2D {
public:
    queue<int> Q;
    Vector2D(vector<vector<int>>& vec) {
        for (auto & row : vec) {
            for (auto & val : row) {
                Q.push(val);
            }
        }
    }
    
    int next() {
        int ret = Q.front(); Q.pop();
        return ret;
    }
    
    bool hasNext() {
        return !Q.empty();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */