class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(begin(words), end(words), [](const string& w1, const string& w2) {
            return w1.size() < w2.size();
        });
        
        int n = words.size();
        unordered_map<string, int> dp;
        
        int ans = -1, maxLen, preIdx;
        for (auto & w : words) {
            maxLen = 1;
            for (int i=0; i<w.size(); i++) {
                string combined = w.substr(0, i) + w.substr(i+1);
                auto findPre = dp.find(combined);
                if (findPre == dp.end()) continue;
                preIdx = findPre->second;
                maxLen = max(dp[combined] + 1, maxLen);
            }
            
            dp[w] = maxLen;
            ans = max(ans, dp[w]);
        }
        
        return ans;
    }
};