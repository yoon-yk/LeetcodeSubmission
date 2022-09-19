class Solution {
public:
    
    /*
                 106
                
                1 0 6
                10 6
                1 06 <-- invalid
                106 <-- invalid
   
   [1 0 6]
    1 2 2
    
    dp[i] = (if it is continuing digit - dp[i-2]) + (if it is separate digit - dp[i-1])
   
    - prune
    if the number is not in a range[1, 26] 
    if the string is starting with 0 and having more than one char
    
    */
    
    int numDecodings(string s) {
        
        int numOfWays = 0;
        
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i=0; i<n; i++) {
            
            if (i > 0) {
                string newStr = s.substr(i-1, 2);
                if (s[i-1] != '0' && stoi(newStr) > 0 && stoi(newStr) < 27) 
                    dp[i+1] += dp[i-1];
            }
                        
            if (s[i]!= '0') {
                dp[i+1] += dp[i];
            }
        }
        
//         for (auto d : dp)
//             cout << d << " ";
//         cout << endl;
        
        return dp[n]; // number of ways to decode the string 
    }
};