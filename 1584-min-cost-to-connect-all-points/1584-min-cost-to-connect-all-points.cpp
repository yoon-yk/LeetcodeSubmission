class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    bool newlyUnited(int x, int y) {
        int p1 = find(x), p2 = find(y);
        if (p1 == p2) return false;
        parent[p1] = p2;
        return true;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        parent.resize(points.size());
        iota(parent.begin(), parent.end(), 0);
        
        priority_queue<vector<int>, 
        vector<vector<int>>, greater<vector<int>>> pq;
        
        int dist, x, y;
        for (int i=0; i<points.size(); ++i) {
            for (int j=0; j<i; ++j) {
                pq.push({abs(points[i][0]-points[j][0]) +
                              abs(points[i][1]-points[j][1]),
                             i, j});
            }
        }
        
        int comp = points.size(), sum = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            dist = cur[0], x = cur[1], y = cur[2];
            
            if (newlyUnited(x, y)) {
                sum += dist;
                --comp;
                if (comp == 1) {
                    return sum;
                }
            }
        }
        
        return 0;
    }
};