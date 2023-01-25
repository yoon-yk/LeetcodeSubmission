class Solution {
public:
    vector<int> parent;
    
    int findd (int v) {
        if (parent[v] == v) return v;
        return parent[v] = findd(parent[v]);
    }
    
    bool isConnected(int v1, int v2) {
        int p1 = findd(v1), p2 = findd(v2);
        if (p1 == p2) return true;
        parent[p1] = p2;
        return false;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // valid tree - one component, no cycle
        
        if (edges.size() != n-1) return false;
        
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        int nComp = n;
        for (auto & e : edges) {
            if (!isConnected(e[0], e[1])) {
                --nComp;
            }
        }
        
        return (nComp == 1);
    }
};