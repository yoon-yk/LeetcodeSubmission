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

      vector<vector<int>> std = {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
      };
        
      unordered_map <char,int> m;
      for (auto v: std) {
        m[v[0]] = v[1];
      }

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