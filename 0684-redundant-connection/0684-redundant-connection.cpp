class Solution {
public:
    vector<int> parent;
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    bool unionn(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return false;
        parent[p1] = p2;
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), v1, v2;
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        vector<vector<int>> adjList(n+1);
        for (auto & v : edges) {
            v1 = v[0], v2 = v[1];
            if (!unionn(v1, v2))
                return v;
        }
        return {};
    }
};