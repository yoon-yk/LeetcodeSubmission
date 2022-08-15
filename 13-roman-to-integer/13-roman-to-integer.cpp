class Solution {
  public:

    /*
    
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
    
    */

    int romanToInt(string s) {

      unordered_map <char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

      // acceptable 
      int ans = 0;
      // char
      int i;
      for (i = 0; i < s.length() - 1; i++) {
        if (m[s[i + 1]] > m[s[i]]) {
          ans += m[s[i + 1]] - m[s[i]];
          i ++;
        } else {
          ans += m[s[i]];
        }
      }
      if (i == s.length() - 1)
        ans += m[s[i]];

      return ans;
    }
};