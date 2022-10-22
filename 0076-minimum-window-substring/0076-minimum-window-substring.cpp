class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> dict(256);
        for (char& ch : t) dict[ch]++;
        
        char curCh;
        int cnt = t.size();
        int minLen = INT_MAX, minStart = 0, start = 0;
        for (int end=0; end<s.size(); end++) {
            curCh = s[end];
            dict[curCh]--;
            if (dict[curCh] >= 0)
                cnt--;
            
            while (cnt == 0) {
                if (end - start +1 < minLen) {
                    minLen = end - start +1;
                    minStart = start;
                }
                
                if (dict[s[start]] == 0)
                    cnt++;
                dict[s[start]]++;
                start ++;
            }
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
        
    }
};