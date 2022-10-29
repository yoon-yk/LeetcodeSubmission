class Solution {
public:
    vector<int> arr;
    vector<long long> size;
    
    int find(int x) {
        int y = arr[x];
        if (y != x)
            y = find(arr[x]);
        return arr[x] = y;
    }
    
    bool unionn(int a, int b) {
        int ap = find(a);
        int bp = find(b);
        
        if (ap == bp) // already united
            return false;
        
        if (size[ap] < size[bp]) {
            arr[ap] = bp;
            size[bp] += size[ap];
            size[ap] = 0;
        } else {
            arr[bp] = ap;
            size[ap] += size[bp];
            size[bp] = 0;
        }
        return true;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        arr.resize(n), size.resize(n, 1);
        for (int i=0; i<n; i++) arr[i] = i;
        
        int cnt = n;
        for (auto & e : edges) {
            if (unionn(e[0], e[1]))
                cnt--;
        }
        
        long long ans = 0;
        for (int i=0; i<n; i++) {
            if (size[i] == 0) continue;
            ans += (size[i] * (n-size[i]));
        }

        return ans >> 1;
    }
};