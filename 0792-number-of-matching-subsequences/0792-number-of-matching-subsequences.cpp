class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int ans = 0;
        vector<vector<const char*>> waiting(128);
        for (auto & w : words) {
            waiting[w[0]].push_back(w.c_str());
        }
        
        for (auto &c : s) {
            auto ws = waiting[c];
            waiting[c].clear();
            
            for (auto & w : ws) {
                waiting[*(++w)].push_back(w);
            }
        }
        
        return waiting[0].size();
    }
};