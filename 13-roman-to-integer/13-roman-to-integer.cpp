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

      unordered_map <char,int> m = {
          {'I', 1},
          {'V', 5},
          {'X', 10},
          {'L', 50},
          {'C', 100},
          {'D', 500},
          {'M', 1000}
      };

      // acceptable 
      int ans = 0;
      // char
      int i;
      for (i = 0; i < s.length(); i++) {
        if (i+1 < s.length() && m[s[i + 1]] > m[s[i]]) {
          ans += m[s[i + 1]] - m[s[i]];
          i ++;
        } else 
          ans += m[s[i]];
      }

      return ans;
    }
};