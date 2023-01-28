class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        int oneCnt, zeroCnt;
        for (int i=0; i<strs.size(); ++i) {
            oneCnt = countOnes(strs[i]), zeroCnt = strs[i].size()-oneCnt;
            for (int zeroes = m; zeroes >= zeroCnt; --zeroes) {
                for (int ones = n; ones >= oneCnt; --ones) {
                    dp[zeroes][ones] = max(1 + dp[zeroes - zeroCnt][ones - oneCnt],
                                          dp[zeroes][ones]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    int countOnes(string & s) {
        int ans = 0;
        for (auto & c : s) 
            ans += (c == '1');
        return ans;
    }
};