class Solution {
public:
    
    vector<int> parent; 
    
    int findParent (int src) {
        if (src != parent[src])
            return parent[src] = findParent(parent[src]);
        return parent[src];
    }
    
    void makeSameGroup(int u , int v) {
        int pu = findParent(u) ; 
        int pv = findParent(v);
        parent[pu] = pv; 
    }

    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        
        parent.resize(n);
        
        for (int i=0; i<n; i++){
            parent[i] = i;
        }

        for (const auto& e : edges) {
            makeSameGroup(e[0],e[1]);
        }
        
        return (findParent(src) == findParent(des));
    }
};