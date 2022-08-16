class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> v(n+2, 0);
        
        for (auto e : edges) {
            if (v[e[0]]++ > 0) return e[0];
            if (v[e[1]]++ > 0) return e[1];
        }
        
        return 0;
    }
};