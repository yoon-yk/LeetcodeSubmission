class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> dict(58, 0);
        int curE, cnt = 0, ans = s.size()+1, start = 0, ansStart;
        
        for (auto & c : t) {
            ++dict[c-'A'];
            if (dict[c-'A'] == 1) ++cnt;
        }
        
        for (int end=0; end<s.size(); ++end) {
            if (--dict[s[end]-'A'] == 0) --cnt;
            
            while (cnt == 0) {
                ++dict[s[start]-'A'];
                if (dict[s[start]-'A'] == 1) ++cnt;
                if (ans > end-start+1) {
                    ans = end-start+1;
                    ansStart = start;
                }
                ++start;
            }
        }
        return (ans > s.size()) ? "" : s.substr(ansStart,ans);
    }
};