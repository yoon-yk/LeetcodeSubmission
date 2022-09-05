class Solution {
public:
    vector<int> group;
    
    int findParent(int idx) {
        if (group[idx] == idx)
            return idx;
        return group[idx] = findParent(group[idx]);
    }
    
    void unionG(int i1, int i2) {
        int p1 = findParent(i1);
        int p2 = findParent(i2);
        group[p1] = p2;
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        
        int nComp = n;
        sort(logs.begin(), logs.end());
        group.resize(n);
        for (int i=0; i<n; i++)
            group[i] = i;
        
        for (auto& lg : logs) {
            if (findParent(lg[1])!=findParent(lg[2])) {
                unionG(lg[1], lg[2]);
                nComp--;
            }
            if (nComp == 1)
                return lg[0];
        }
        
        return -1;
        
    }
};