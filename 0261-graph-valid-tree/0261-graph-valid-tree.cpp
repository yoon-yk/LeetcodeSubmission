class Solution {
public:
    vector<int> parent;
    vector<int> size;
    
    int find(int e) {
        if (parent[e] == e)
            return e;
        return parent[e] = find(parent[e]);
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // TREE 
        // NO Cycle -- # edges == n-1
        if (edges.size() != n-1)
            return false;
        // ONLY one component
        parent.resize(n);
        size.resize(n, 1);
        for (int i=0; i<n; i++) parent[i] = i;
        
        int compN = n;
        int p1, p2;
        for (auto& e : edges) {
            p1 = find(e[0]), p2 = find(e[1]);
            if (p1 == p2) 
                return false;
        
            if (size[p1] > size[p2]) {
                parent[p2] = p1;
                size[p1] += size[p2];
            } else {
                parent[p1] = p2;
                size[p2] += size[p1];
            }
            compN--;

        }
        
        return (compN==1);
    }
};