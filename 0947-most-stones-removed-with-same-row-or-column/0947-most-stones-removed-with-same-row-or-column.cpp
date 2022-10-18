class Solution {
public:
    const int K = 10001;

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
        vector<int> rep(2*K + 1);
        vector<int> size(2*K + 1);
        
        for (int i=0; i< 2*K + 1; i++) {
            rep[i] = i, size[i] = 1;
        }
        
        int componentCount = 0;
        unordered_map<int, int> marked;
        for (vector<int>& stone : stones) {
            if (!marked.count(stone[0]))
                componentCount++;
            if (!marked.count(stone[1]+K))
                componentCount++;
            marked[stone[0]] = 1;
            marked[stone[1]+K] = 1;
        }
        
        for (int i=0; i<stones.size(); i++) {
            int x = stones[i][0], y = stones[i][1] + K;
            componentCount -= performUnion(rep, size, x, y);
        }
        
        return stones.size() - componentCount;
    }
};