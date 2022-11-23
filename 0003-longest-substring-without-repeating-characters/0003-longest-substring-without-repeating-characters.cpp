class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, ans = 0;
        int n = s.size();
        unordered_map<char, int> dict;
        for (; end<n; end++) {
            dict[s[end]]++;
            
            while (dict[s[end]] > 1) {
                dict[s[start]] --;
                start ++;
            }
            // cout << start << " " << end << endl;
            ans = max(end-start+1, ans);
        }
        return ans;
    }
};