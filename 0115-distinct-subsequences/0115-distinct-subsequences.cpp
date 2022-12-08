class Solution {
public:
//     int numDistinct(string s, string t) {
//         int len1=s.size(), len2 = t.size();
//         vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
//         for (int i=len1; i>=0; --i) {
//             for (int j=len2; j>=0; --j) {

//                 // i == len1 || j == len2
//                 if (i==len1 || j == len2){
//                     dp[i][j] = 1;
//                 }
                
//                 else if (s[i] == t[j]) {
//                     dp[i][j] += dp[i+1][j+1];
//                 } else {
//                     dp[i][j] = dp[i+1][j];
//                 }
                
//             }
//         }
        
//         for (int i=0; i<=len1; ++i) {
//             for (int j=0; j<=len2; ++j) {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
        
//         return 0;
//     }
    
    int numDistinct(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        long long ret;
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        dp[len1][len2] = 1;
        for (int i=len1; i>=0; --i) {
            for (int j=len2; j>=0; --j) {
                if (i==len1 || j == len2) {
                    dp[i][j] = (j==len2);
                    continue;
                }
                ret = 0;
                if (s[i] == t[j]) ret += dp[i+1][j+1];
                ret += dp[i+1][j]; 
                dp[i][j] = ret;
            }
        } 
        
        
        return dp[0][0];
    }
};