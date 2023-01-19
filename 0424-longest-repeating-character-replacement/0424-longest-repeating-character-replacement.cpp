class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), ans = 0, start = 0, maxFreq = 0;
        vector<int> freq(256, 0);
        for (int end=0; end<n; ++end) {
            ++freq[s[end]];
            maxFreq = *max_element(freq.begin(), freq.end());
            if ((end-start+1)-maxFreq > k) {
                --freq[s[start]], ++start;
            }
            // cout << s.substr(start, end-start+1) << " " << maxFreq << endl;
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};