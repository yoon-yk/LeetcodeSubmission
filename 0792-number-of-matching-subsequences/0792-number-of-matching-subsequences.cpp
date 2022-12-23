class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<const char*>> alpha(26);
        for (auto & word : words) alpha[word[0]-'a'].push_back(word.c_str());
        
        int ans = 0;
        for (auto & c : s) {
            auto collect = alpha[c-'a'];
            alpha[c-'a'].clear();
            
            for (auto& cur : collect) {
                if ((*(++cur)) == '\0') ++ans;
                else alpha[(*cur)-'a'].push_back(cur);
            }
        }
        
        return ans;
        
    }
};