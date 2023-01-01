class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& src, vector<string>& targets) {
        int len;
        vector<int> change(s.size(), -1);
        for (int i=0; i<indices.size(); ++i) {
            len = src[i].size();
            if (s.substr(indices[i], len) == src[i])
                change[indices[i]] = i;
        }
        
        string ans;
        for (int i=0; i<change.size(); ++i) {
            if (change[i] == -1) ans += s[i];
            else {
                ans += targets[change[i]];
                i += src[change[i]].size()-1;
            }
        }
        return ans;
        
    }
};