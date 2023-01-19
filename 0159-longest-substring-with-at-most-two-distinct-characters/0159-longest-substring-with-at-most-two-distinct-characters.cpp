class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> idx(256, 0);
        int start = 0, ans = 0, cnt = 0;
        for (int end=0; end<s.size(); ++end) {
            ++idx[s[end]];
            if (idx[s[end]] == 1) ++cnt;
            
            while (cnt > 2) {
                --idx[s[start]];
                if (idx[s[start]] == 0) --cnt;
                ++start;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};