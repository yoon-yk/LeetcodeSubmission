class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> l(n);
        /// min(l[i], r[i])
        l[0] = 0;
        for (int i=1; i<n-1; ++i) 
            l[i] = max(l[i-1], h[i-1]);
        
        int ans = 0, maxR = 0;
        for (int i=n-2; i>=0; --i) {
            maxR = max(maxR, h[i+1]);
            ans += max(0, (min(l[i], maxR)-h[i]));
        }
        return ans;
        
    }
};