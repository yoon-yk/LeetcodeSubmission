class Solution {
public:
    string getHint(string s, string g) {
        vector<int> mp(10, 0);
        
        int nB = 0, nC = 0;
        for (int i=0; i<g.size(); ++i) {
            if (s[i] == g[i]) {
                ++nB;
            } else {
                if (mp[s[i]-'0'] < 0) ++nC;
                if (mp[g[i]-'0'] > 0) ++nC;
                ++mp[s[i]-'0'], --mp[g[i]-'0'];
            }      
        }
        
        return to_string(nB)+'A'+to_string(nC)+'B';
    }
};