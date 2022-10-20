class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), res = 0;
        unordered_map<char, int> mp; 
        // key = char, value = char이 들어가지 않는
        
        int start = 0;
        for (int end=0; end<n; end++) {
            if (mp[s[end]] > 0)
                start = max(mp[s[end]], start);
            res = max(res, end-start+1);
            mp[s[end]] = end + 1; 
        }
        
        return res;
    }
};