class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        
        /*
            8 1 5 2 6
        a : 8 8 8 8 10
        b : 3 3 3 2 MIN
        
            
        */
        
        int n = values.size();
        vector<int> a(n), b(n);
        a[0] = values[0];
        for (int i=1; i<n-1; ++i) {
            a[i] = max(a[i-1], values[i] + i);
        }
        
        b[n-1] = INT_MIN;
        for (int i=n-2; i>=0; --i) {
            b[i] = max(values[i+1]-i-1, b[i+1]);
        }
    
        int ans = -1;
        for (int i=0; i<n; i++) {        
            ans = max(ans, a[i] + b[i]);
        }
        
        return ans;
    }
};