class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n = values.size();
        int curMax = values[0], ans = INT_MIN;
        for (int i=1; i<n; ++i) {
            ans = max(curMax+(values[i]-i), ans);
            curMax = max(curMax, values[i]+i);
        }
        
        return ans;
    }
};