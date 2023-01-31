class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // [start ... end] 
        // end가 이미 본 애라면 start+1
        // 그렇지 않다면 계속 유지
        vector<int> freq(256, 0);
        int start = 0, end = 0, n = s.size(), ans = 0;
        for (; end < n; ++end) {
            ++freq[s[end]];
            while (freq[s[end]] > 1) {
                --freq[s[start]];
                ++start;
            }
            ans = max(end-start+1, ans);
        }
        return ans;
    }
};