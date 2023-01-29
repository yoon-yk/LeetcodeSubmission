class Solution {
public:
    #define a 0
    #define e 1
    #define i 2
    #define o 3
    #define u 4
    
    int countVowelPermutation(int n) {
        unordered_map<int, vector<int>> dict = {
            {a, {e}},
            {e, {a, i}},
            {i, {a, e, o, u}}, 
            {o, {i, u}},
            {u, {a}}
        };
        
        /*
        base case 
        dp[n][every vowel] = 1
        
        recurrence relation
        dp[i][j] = dp[i+1][followed vowel]
        */
        
        int kVowelCnt = 5, mod = 1e9+7;
        vector<vector<int>> dp (n+1, vector<int>(5));
        for (int c=0; c<kVowelCnt; ++c) dp[n][c] = 1;
        
        for (int idx=n-1; idx>0; --idx){
            for (int v=0; v<kVowelCnt; ++v) {
                for (auto & followed : dict[v]) {
                    dp[idx][v] = (dp[idx][v] + dp[idx+1][followed]) % mod;
                }
            }
        }
        
       // for (int idx=0; idx<=n; ++idx){
       //      for (int v=0; v<kVowelCnt; ++v) {
       //          cout << dp[idx][v] << " ";
       //      }
       //     cout << endl;
       // }
      
        int ans = 0;
        for (int v=0; v<kVowelCnt; ++v) {
            ans = (ans + dp[1][v]) % mod;
        }
        return ans;
    }
};