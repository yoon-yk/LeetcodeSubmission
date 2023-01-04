class Solution {
public:
    string & encode (string &str) {
        vector<int> seen(256, -1);
        int cnt = 0;
        for (int i=0; i<str.size(); i++) {
            int c = str[i];
            if (seen[c] == -1)
                seen[c] = cnt++;
            str[i] = seen[c];
        }
        return str;
    }
    bool isIsomorphic(string s, string t) {
        return encode(s) == encode(t);
    }
};