class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map <char, int> m;
        for (int i=0; i<s.length(); i++) {
            if (m.count(s[i]))
                m[s[i]] = -1;
            else 
                m[s[i]] = i;
        }
            
        
        int ans = INT_MAX;
        for (auto c : m)
            if (c.second >= 0) ans = min(ans, c.second);
           
        return (ans == INT_MAX)? -1 : ans;
    }
};