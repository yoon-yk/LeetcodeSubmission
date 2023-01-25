class Solution {
public:
    vector<int> parent;
    
    int findd(int v) {
        if (parent[v] == v) return v;
        return parent[v] = findd(parent[v]);
    }
    
    bool unionn(int v1, int v2) {
        int p1 = findd(v1), p2 = findd(v2);
        if (p1 == p2) return true;
        parent[p1] = p2;
        return false;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        
        int nComp = n;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (isConnected[i][j] && !unionn(i, j)) {
                    --nComp;
                }
            }
        }
        return nComp;
        
    }
};