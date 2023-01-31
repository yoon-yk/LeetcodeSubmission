class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // [start ... end] 
        // end가 이미 본 애라면 start+1
        // 그렇지 않다면 계속 유지
        vector<int> lastSeen(256, -1);
        int start = 0, end = 0, n = s.size(), ans = 0;
        for (; end < n; ++end) {
            if (lastSeen[s[end]] >= start) {
                start = lastSeen[s[end]] + 1;
            }
            lastSeen[s[end]] = end;
            ans = max(end-start+1, ans);
        }
        return ans;
    }
};