class Solution {
public:
    vector<int> parent;
    
    int findd (int idx) {
        if (parent[idx] == idx)
            return idx;
        return parent[idx] = findd(parent[idx]);
    }
    
    bool isNewlyUnited(int n1, int n2) {
        int p1 = findd(n1);
        int p2 = findd(n2);
        parent[p1] = p2;
        return (p1 != p2);
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
    
        parent.resize(n);
        for (int i=0; i<n; i++)
            parent[i] = i;
        
        int cnt = n;
        for (auto & e : edges) {
            if (isNewlyUnited(e[0], e[1]))
                cnt --;
        }
        
        return cnt;
    }
};