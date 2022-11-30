class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(begin(words), end(words), [](string& w1, string& w2) {
            return w1.size() < w2.size();
        });
        
        int n = words.size();
        vector<int> dp(n);
        unordered_map<string, int> mp;
        
        int idx = 0, ans = -1, maxLen, preIdx;
        for (auto & w : words) {
            maxLen = 1;
            for (int i=0; i<w.size(); i++) {
                string combined = w.substr(0, i) + w.substr(i+1);
                auto findPre = mp.find(combined);
                if (findPre == mp.end()) continue;
                preIdx = findPre->second;
                maxLen = max(dp[preIdx] + 1, maxLen);
            }
            
            mp[w] = idx;
            dp[idx] = maxLen;
            ans = max(ans, dp[idx]);
            idx++;
        }
        
        return ans;
    }
};