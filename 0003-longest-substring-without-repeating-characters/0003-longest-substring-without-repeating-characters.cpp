class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0, start = 0;
        vector<int> freq(256, 0);
        for (int end=0; end<n; ++end) {
            ++freq[s[end]];
            while (freq[s[end]] > 1) {
                --freq[s[start]];
                ++start;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};