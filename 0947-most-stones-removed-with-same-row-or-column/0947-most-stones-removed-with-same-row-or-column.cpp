class Solution {
public:
    unordered_map<int, int> par;
    unordered_map<int, int> sz;

    int find(int v) {
        if (par[v] == v) return v;
        return par[v] = find(par[v]);
    }
    
    void unionn(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return;
        if (par[p1] < par[p2]) {
            par[p1] = p2;
            sz[p2] += p1;
            sz.erase(p1);
        } else {
            par[p2] = p1;
            sz[p1] += p2;
            sz.erase(p2);
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        /*
          0 1 2 3
        0 x x x
        1   x
        2       x
        3   x
        
        총 vertex의 개수 - component의 개수
        
        
        */
        
        int kColBase = 10001; // row 0 = 0, col 0 = 10001
        
        int r, c;
        for (auto & stone : stones) {
            r = stone[0], c = stone[1] + kColBase;
            if (!par.count(r)) {par[r] = r, sz[r] = 1;}
            if (!par.count(c)) {par[c] = c, sz[c] = 1;}
            unionn(r, c);
        }
        
        
        return stones.size() - sz.size();
        
    }
};