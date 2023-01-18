class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(267, -1);
        int curCh, start = 0, ans = 0;
        for (int end=0; end<s.size(); ++end) {
            curCh = s[end];
            if (m[curCh] >= start) start = m[curCh]+1;
            m[curCh] = end;
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};