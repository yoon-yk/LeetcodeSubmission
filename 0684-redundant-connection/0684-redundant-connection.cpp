class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find (int idx) {
        if (parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    
    void unionn (int idx1, int idx2) {
        int p1 = find(idx1), p2 = find(idx2);
        if (size[p1] > size[p2]) {
            parent[p2] = p1;
            size[p1] += size[p2];
        } else {
            parent[p1] = p2;
            size[p2] += size[p1];
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        parent.resize(1001);
        size.resize(1001, 1);
        for (int i=0; i<=1000; ++i) parent[i] = i;
        
        for (auto & e : edges) {
            int p1 = find(e[0]), p2 = find(e[1]);
            if (p1 == p2) return e;
            unionn(e[0], e[1]);
        }
        
        return {};
    }
};