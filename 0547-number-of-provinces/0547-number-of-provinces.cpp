class Solution {
public:
    vector<int> parent;
    
    void initialize(int n) {
        parent.resize(n);
        for (int i=0; i<n; i++)
            parent[i] = i;
    }
    
    int find (int elm) {
        if (parent[elm] == elm) return elm;
        return parent[elm] = find(parent[elm]);
    }
    
    void unionn(int e1, int e2) {
        int par1 = find(e1), par2 = find(e2);
        parent[par1] = par2;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        initialize(n);
        int cnt = n;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (!isConnected[i][j] || find(i) == find(j)) continue;
                unionn(i, j);
                cnt--;
            }
        }
        
        return cnt;
    }
};