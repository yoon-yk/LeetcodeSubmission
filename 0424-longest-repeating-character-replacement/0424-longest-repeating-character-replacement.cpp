class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0, start = 0, maxFreq = 0;
        vector<int> freq(256, 0);
        for (int end=0; end<n; ++end) {
            ++freq[s[end]];
            maxFreq = max(maxFreq, freq[s[end]]);
            if ((end-start+1)-maxFreq > k) {
                --freq[s[start]], ++start;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};