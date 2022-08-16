class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> v(n+2, 0);
        
        for (const auto &e : edges) {
            v[e[0]]++, v[e[1]]++;
        }
        
        int ans = -1;
        for (int i=1; i<=n+1; i++) {
            if (v[i] == n) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};