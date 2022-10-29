class Solution {
public:
    vector<int> arr;
    vector<long long> size;
    
    int find(int x) {
        if (arr[x] == x)
            return x;
        return arr[x] = find(arr[x]);

    }
    
    void unionn(int a, int b) {
        int ap = find(a);
        int bp = find(b);
        
        if (ap == bp) // already united
            return;
        
        if (size[ap] < size[bp]) {
            arr[ap] = bp;
            size[bp] += size[ap];
            size[ap] = 0;
        } else {
            arr[bp] = ap;
            size[ap] += size[bp];
            size[bp] = 0;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        arr.resize(n), size.resize(n, 1);
        for (int i=0; i<n; i++) arr[i] = i;
        
        for (auto & e : edges) 
            unionn(e[0], e[1]);
        
        long long ans = 0;
        int rest = n;
        for (int i=0; i<n; i++) {
            if (size[i] == 0) continue;
            rest -= size[i];
            ans += (size[i] * rest);
        }
        // 5+4+3+2+1 
        
        // 4 3 
        // 2 1 
        // 1*3 + 1*2 + 1*1  
        return ans;

        // return ans >> 1;
    }
};