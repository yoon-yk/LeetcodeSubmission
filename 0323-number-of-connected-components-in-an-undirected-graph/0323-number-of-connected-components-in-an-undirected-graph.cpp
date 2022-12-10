class Solution {
public:
    
    vector<int> parent;
    
    int findd(int e1) {
        if (parent[e1] == e1) return e1;
        return parent[e1] = findd(parent[e1]);
    }
    
    void unionn(int e1, int e2) {
        parent[parent[e1]] = parent[e2];
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        
        parent.resize(n);
        for (int i=0; i<n; ++i) parent[i] = i;
        
        int cnt = n;
        for (auto &e : edges) {
            int p1 = findd(e[0]);
            int p2 = findd(e[1]);
            
            if (p1!=p2) {
                unionn(e[0], e[1]);
                cnt--;
            }
        }
        
        return cnt;
        
    }
};