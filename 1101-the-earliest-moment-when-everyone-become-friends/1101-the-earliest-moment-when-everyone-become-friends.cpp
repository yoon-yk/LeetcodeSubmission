class Solution {
public:
    vector<int> parent, size;
    
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    bool unionn(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return true;
        if (size[p1] < size[p2]) {
            size[p2] += size[p1];
            parent[p1] = p2;
        } else {
            size[p1] += size[p2];
            parent[p2] = p1;
        }
        return false;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        parent.resize(n);       
        size.resize(n, 1);
        for (int i=0; i<parent.size(); ++i) parent[i] = i;
        
        sort(logs.begin(), logs.end());
        
        int cnt = n;
        for (auto & log : logs) {
            if (!unionn(log[1], log[2])) {
                --cnt;
                if (cnt == 1) return log[0];
            }
        }
        
        return -1;
        
    }
};