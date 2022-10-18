class Solution {
public:
    
    int shareSameRowOrCol(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] || a[1] == b[1];
    }
    
    int find (vector<int>& rep, int x) {
        if (x == rep[x])
            return x;
        return rep[x] = find(rep, rep[x]);
    }
    
    int performUnion(vector<int>& rep, vector<int>& size, int x, int y) {
        x = find(rep, x);
        y = find(rep, y);
        
        if (x == y) 
            return 0;
        
        if (size[x] > size[y]) {
            rep[y] = x;
            size[x] += size[y];
        } else {
            rep[x] = y;
            size[y] += size[x];
        }
        
        return 1;
    }
    
    int removeStones(vector<vector<int>>& stones) {
     
        vector<int> rep(stones.size());
        vector<int> size(stones.size());
        
        for (int i=0; i<stones.size(); i++) {
            rep[i] = i, size[i] = 1;
        }
        
        int componentCount = stones.size();
        for (int i=0; i<stones.size(); i++) {
            for (int j=i+1; j<stones.size(); j++) {
                if (shareSameRowOrCol(stones[i], stones[j])) {
                    componentCount -= performUnion(rep, size, i, j);
                }
            }
        }
        
        return stones.size() - componentCount;
    }
};