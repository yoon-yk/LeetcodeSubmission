class Solution {
public:
    int find(int idx, vector<int> &parent){
        if (parent[idx] == idx)
            return idx;
        return parent[idx] = find(parent[idx], parent);
    }
    
    bool wasConnected (int n1, int n2, vector<int>& parent) {
        int p1 = find(n1, parent);
        int p2 = find(n2, parent);
        parent[p1] = p2;
        return (p1 == p2);
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // no cycle
        // just one component
        
        if (edges.size() != (n-1)) return false;
        
        vector<int> parent (n);
        for (int i=0; i<n; i++) 
            parent[i] = i;
        
        int cnt = n;
        for (auto & e : edges) {
            if (wasConnected(e[0], e[1], parent))
                return false;
        }
        
        return true;
    }
};