class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (auto c:t) map[c]++;
        int counter = t.size(), begin = 0, end = 0;
        int minLen = INT_MAX, minLeft = -1;
        
        while (end < s.size()) {
            
            if (--map[s[end]] >= 0)
                -- counter;
            
            while (!counter) {
                if (end-begin+1 < minLen) {
                    minLen = end-begin+1;
                    minLeft = begin;
                }
                if (map[s[begin]] == 0)
                    ++ counter;
                ++ map[s[begin]];
                ++ begin;
            }
            
            ++end;
        }
        return (minLen == INT_MAX)? "" : s.substr(minLeft, minLen);
    }
};