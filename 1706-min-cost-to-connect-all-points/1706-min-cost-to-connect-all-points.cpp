class UnionFind {
public:
    vector<int> parent;

    UnionFind(int n){
        for (int i=0; i<n; ++i) 
            parent.push_back(i);
    }

    int find(int p) {
        if (p == parent[p]) return p;
        return parent[p] = find(parent[p]);
    }

    void uni(int a, int b) {
        int p1 = find(a), p2 = find(b);
        parent[p1] = p2;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        UnionFind uf(n);

        for (int i=0; i<n; ++i) {
            auto & p1 = points[i];
            for (int j=i+1; j<n; ++j) {
                auto & p2 = points[j];
                int dist = abs(p1[0]-p2[0]) + abs(p1[1]-p2[1]);
                pq.push({dist, i, j});
            }
        }

        int ans = 0, comp = n; 
        while (!pq.empty() && comp > 1) {
            auto cur = pq.top(); pq.pop();
            int dist = cur[0], pt1 = cur[1], pt2 = cur[2];
            if (uf.find(pt1) == uf.find(pt2)) continue;
            uf.uni(pt1, pt2);
            ans += dist;
            --comp;
        }

        return ans;
    }
};