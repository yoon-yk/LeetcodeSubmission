class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> m(26, -1);
        for (int i=0; i<s.length(); i++) {
            if (m[s[i]-'a'] == -2)
                continue;
            else if (m[s[i]-'a'] >= 0)
                m[s[i]-'a'] = -2;
            else 
                m[s[i]-'a'] = i;
        }
            
        
        int ans = INT_MAX;
        for (auto c : m)
            if (c >= 0) 
                ans = min(ans, c);
           
        return (ans == INT_MAX)? -1 : ans;
    }
};