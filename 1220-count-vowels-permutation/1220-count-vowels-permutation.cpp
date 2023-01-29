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
        vector<int> cur(5), next(5);
        for (int c=0; c<kVowelCnt; ++c) next[c] = 1;
        
        for (int idx=n-1; idx>0; --idx){
            for (int v=0; v<kVowelCnt; ++v) {
                cur[v] = 0;
                for (auto & followed : dict[v]) {
                    cur[v] = (cur[v] + next[followed]) % mod;
                }
            }
            next = cur;

        }
        
       // for (int idx=0; idx<=n; ++idx){
       //      for (int v=0; v<kVowelCnt; ++v) {
       //          cout << dp[idx][v] << " ";
       //      }
       //     cout << endl;
       // }
      
        int ans = 0;
        for (int v=0; v<kVowelCnt; ++v) {
            ans = (ans + next[v]) % mod;
        }
        return ans;
    }
};