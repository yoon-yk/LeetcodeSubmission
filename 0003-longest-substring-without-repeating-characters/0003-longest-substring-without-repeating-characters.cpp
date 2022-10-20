class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars;

        int res = 0;
        int left = 0, right = 0;

        char curCh, leftCh;
        while (right < s.length()) {
            curCh = s[right];
            chars[curCh]++;

            while (chars[curCh] > 1) {
                leftCh = s[left];
                chars[leftCh]--;
                left++;
            }

            res = max(res, right - left + 1);

            right++;
        }

        return res;
    }
};