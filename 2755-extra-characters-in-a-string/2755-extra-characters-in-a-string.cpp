class Solution {
public:
    int minExtraChar(string str, vector<string>& d) {

        unordered_set<string> dict(d.begin(), d.end());

        int n = str.size();
        vector<int> dp(n+1, 0);
        for (int s=n-1; s>=0; --s) {
            dp[s] = dp[s+1]+1;

            for (int e=s; e<n; ++e) {
                auto cur = str.substr(s, e-s+1);

                if (dict.count(cur)) {
                    dp[s] = min(dp[s], dp[e+1]); // 
                }
            }
        }

        return dp[0];
    }
};