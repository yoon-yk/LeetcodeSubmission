class Solution {
public:
    vector<int> parent, size;
    
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    void unionn(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (size[p1] < size[p2]) {
            parent[p1] = parent[p2]; 
            size[p2] += size[p1]; 
        } else {
            parent[p2] = parent[p1]; 
            size[p1] += size[p2]; 
        }
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i=0; i<n; ++i) parent[i] = i;
        sort(logs.begin(), logs.end());
        
        int p1, p2, nGroup = n;
        for (auto & log : logs) {
            p1 = find(log[1]), p2 = find(log[2]);
            if (p1 != p2) {unionn(log[1], log[2]); --nGroup; }
            if (nGroup == 1) return log[0];
        }
        return -1;
    }
};