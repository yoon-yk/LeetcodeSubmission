class Solution {
public:
    vector<int> parent;
    
    int find(int idx) {
        if (parent[idx] == idx) return idx;
        return parent[idx] = find(parent[idx]);
    }
    
    void unionn(int idx1, int idx2) {
        int p1 = find(idx1);
        int p2 = find(idx2);
        
        parent[p1] = p2;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        // 1) # of redundant cable in total
        // 2) # of components -- needs at least (# of c)-1
        
        // if (1) < (2) return -1
        // else then return (# of c)-1
        
        // union and find 
        
        int numE = connections.size();
        
        if (n-1 > numE) return -1;
        
        int redundN = 0;
        int numOfComp = n;
        parent.resize(n);
        for (int i=0; i<n; i++) parent[i] = i;
        
        for (auto & c : connections) {
            int p1 = find(c[0]), p2 = find(c[1]);
            if (p1 != p2) {
                parent[p1] = p2;
                numOfComp --;
            }
        }

        return (numOfComp -1);
        
    }
};