class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
     // a b c d
     // 0 -1 1 -1
        
        vector<int> change(s.size(), -1);
        int n = indices.size();
        for (int i=0; i<n; i++) {
            if (s.substr(indices[i], sources[i].size()) == sources[i]) 
                change[indices[i]] = i;
        }
        
        string ans = "";
        for (int i=0; i<s.size();) {
            if (change[i] > -1) {
                ans += targets[change[i]];
                i += sources[change[i]].size();
            } else {
                ans += s[i];
                i++;
            }
        }
        
        return ans;
    }
};