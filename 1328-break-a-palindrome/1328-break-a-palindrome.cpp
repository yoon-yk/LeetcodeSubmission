class Solution {
public:
    string breakPalindrome(string s) {
        /*
        "abccba"
        "aaccba"
        
        "aaaazaaaa"
        "aaaazaaab"
        "aaaabaaaa"
        
        "bcd"
        "acb"
        */
        
        // string str[3] = {"aaaazaaab", "aaaabaaaa", "aaaazaaaa"};
        // string str[2] = {"abccba", "aaccba"};
        // sort(begin(str), end(str));
        
        // for (string& st : str)
            // cout << st << " ";
        // cout << endl;

        // palindrome 
        // even : <str> <rts>
        // odd : <str> # <rts>
        
        // str이 모두 a라면 rts 에서 맨 끝 늘려주기
        // str에서 a가 아닌게 발견되면 b로 바꿔주기
        
        int n = s.size(), i;
        
        if (n == 1)
            return "";
        
        for (i=0; i<(n>>1); i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }
        s[n-1] = 'b';
        return s;
    }
};