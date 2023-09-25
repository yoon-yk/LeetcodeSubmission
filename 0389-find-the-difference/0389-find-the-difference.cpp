class Solution {
public:
    char findTheDifference(string& s, string& t) {
        vector<int> mp(26, 0);
        for (int i=0; i<s.size(); ++i) {
            ++mp[s[i]-'a'];
        }

        for (int i=0; i<t.size(); ++i) {
            if (mp[t[i]-'a'] == 0) return t[i];
            --mp[t[i]-'a'];
        }
        return -1;
    }
};