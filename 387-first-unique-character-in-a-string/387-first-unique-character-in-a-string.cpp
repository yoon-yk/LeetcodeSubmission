class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> m(26, 0);
        for (int i=0; i<s.length(); i++) { 
            m[s[i]-'a']++;
        }
            
        
        int ans = INT_MAX;
        for (int i=0; i<s.length(); i++) 
            if (m[s[i]-'a'] == 1) {
                ans = i;
                break;
            }
    
        return (ans == INT_MAX)? -1 : ans;
    }
};