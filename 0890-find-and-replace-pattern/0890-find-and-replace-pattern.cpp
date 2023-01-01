class Solution {
public:
    string transform(string s) {
        int cur = 0;
        vector<int> seen(26, -1);
        for (auto &c : s) {
            if (seen[c-'a'] == -1) seen[c-'a'] = cur++;
            c = (seen[c-'a']+'0');
        }
        return s;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        string target = transform(pattern);
        // cout << target << endl;
        for (auto & word : words) {
            // cout << transform(word) << endl;
            if (transform(word) == target)
                ans.push_back(word);
        }
        
        return ans;
    }
};