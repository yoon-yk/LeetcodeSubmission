class Solution {
public:
    string transform(string &s) {
        
        string ans;
        int cur = 0;
        vector<int> seen(26, -1);
        for (auto &c : s) {
            if (seen[c-'a'] == -1) seen[c-'a'] = cur++;
            ans += (seen[c-'a']+'0');
        }
        return ans;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        string target = transform(pattern);
        for (auto & word : words) {
            if (transform(word) == target)
                ans.push_back(word);
        }
        
        return ans;
    }
};