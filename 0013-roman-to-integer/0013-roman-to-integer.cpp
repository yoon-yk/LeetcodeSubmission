class Solution {
public:
    int romanToInt(string s) {
        /*
        Input: s = "III"
        Output: 3
        Explanation: III = 3.
        
        Input: s = "LVIII"
        Output: 58
        Explanation: L = 50, V= 5, III = 3.
        */
        
        unordered_map<char, int> mp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int ans = 0, n = s.size();
        
        char curCh;
        for (int i=0; i<n; ++i) {
            curCh = s[i];
            if (curCh == 'I') {
                if (i+1 < n && s[i+1] == 'V')
                    ans += 4, ++i;
                else if (i+1 < n && s[i+1] == 'X') 
                    ans += 9, ++i;
                else 
                    ans += 1;
            } else if (curCh == 'V') {
                ans += 5;
            } else if (curCh == 'X') {
                if (i+1 < n && s[i+1] == 'L')
                    ans += 40, ++i;
                else if (i+1 < n && s[i+1] == 'C') 
                    ans += 90, ++i;
                else 
                    ans += 10;
            } else if (curCh == 'L') {
                ans += 50;
            } else if (curCh == 'C') {
                if (i+1 < n && s[i+1] == 'D')
                    ans += 400, ++i;
                else if (i+1 < n && s[i+1] == 'M') 
                    ans += 900, ++i;
                else 
                    ans += 100;
            } else if (curCh == 'D') {
                ans += 500;
            } else if (curCh == 'M') {
                ans += 1000;
            } 
        }
        
        
        return ans;
    }
};