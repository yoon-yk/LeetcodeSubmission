class Solution {
public:
    int numDecodings(string s) {
        /*
        "1"
        dp 
        0 1
        1 1
        
        "13"
        dp
        0 1 2
        1 1 2
        
        "103"
        dp
        0 1 2 3
        1 1 1 1
        */
        
        int n = s.size();        
        int prev2 = 1, prev1 = 1, cur = 0;
        for (int i=0; i < s.size(); i++) {
            cur = 0;
            if ( 0 < (s[i]-'0')) cur = prev1; // as an independent num 
            
            if (i-1 >= 0){
                int nn = stoi(s.substr(i-1, 2));
                if (nn > 9 && nn <= 26) cur += prev2; // as a 2-digit num                
            } 
            prev2 = prev1, prev1 = cur;
        }
        
        return cur;
    }
};