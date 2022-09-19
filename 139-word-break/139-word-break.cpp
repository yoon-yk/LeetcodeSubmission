class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        unordered_set<string> st;
        for(auto i: wordDict)
            st.insert(i);
        dp[0] = true;
        for (int i = 1; i < n + 1; i++){
            // cout << "***" << i << "***" << endl;
            string temp;
            
            for (int j = i; j > 0; j--){
                temp = s[j - 1] + temp;
                // cout << temp << endl;
                
                if (st.count(temp)){
                    if (dp[j - 1]){
                        // cout << j-1 << endl;
                        // cout << "dp[" << i << "] = true" << endl;  
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
//         for (int n : dp)
//             cout << n << " ";
//         cout << endl;
        
        return dp[n];
    }
};