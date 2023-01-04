class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        
        /*
            8 1 5 2 6
        a : 8 8 8 8 10
        b : 3 3 3 2 MIN
        
            
        */
        
        int n = values.size();
        vector<int> a(n);
        a[0] = values[0];
        for (int i=1; i<n-1; ++i) {
            a[i] = max(a[i-1], values[i] + i);
        }
    
        
        int ans = -1;
        int bb = INT_MIN;
        for (int i=n-2; i>=0; --i) {
            bb = max(values[i+1]-i-1, bb);
            ans = max(a[i] + bb, ans);
        }
        
        return ans;
    }
};