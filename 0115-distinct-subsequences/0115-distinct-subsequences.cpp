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
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return backtrack(0, 0, s, t, dp);
    }
    
    int backtrack(int idx1, int idx2, string& s, string& t, vector<vector<int>>& dp) {
        
        
        if (idx2 == t.size())
            return 1;
        if (idx1 == s.size())
            return 0;
        
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        int ans = 0;
        
        if (s[idx1] == t[idx2]) 
            ans += backtrack(idx1+1, idx2+1, s, t, dp);
        
        ans += backtrack(idx1+1, idx2, s, t, dp);
        
        return dp[idx1][idx2] = ans;
        
    }
};