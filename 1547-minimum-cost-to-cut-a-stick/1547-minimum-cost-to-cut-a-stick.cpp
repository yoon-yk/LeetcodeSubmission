class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        
        cuts.insert(cuts.begin(), 0); // dummy starting point
        cuts.push_back(n); // dummy ending point

        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return solve(cuts, 0, cuts.size()-1, dp);
    }
    
    int solve(vector<int>& cuts, int start, int end, vector<vector<int>> &dp) {
        if (start + 1 == end) {
            return 0;
        }
        
        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int ans = INT_MAX;
        for (int i=start+1; i<end; ++i) {
            ans = min(ans, solve(cuts, start, i, dp) + solve(cuts, i, end, dp) + cuts[end]-cuts[start]);
        }

        return dp[start][end] = ans;
    }
};