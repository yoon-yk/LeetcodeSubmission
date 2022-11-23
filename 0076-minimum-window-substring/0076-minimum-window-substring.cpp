class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        
        int slen=s.size(), cnt = 0;
        vector<int> tDict(58, 0);
        for (auto & c : t) {
            if (tDict[c-'A'] == 0) cnt++; 
            tDict[c-'A']++;
        }
        
        int start = 0, minStart = -1, minLen = s.size() + 1;
        for (int end=0; end<slen; end++) {
            int curCh = s[end]-'A';
            if (tDict[curCh] == 1) cnt --;
            tDict[curCh] --;
        
            while (cnt == 0) {
                if (end-start+1 < minLen) {
                    minLen = end-start+1;
                    minStart = start;
                }
                int leftCh = s[start]-'A';
                if (tDict[leftCh] == 0) cnt++;
                tDict[leftCh] ++;
                start++;
            }
            
        }
        return (minStart < 0) ? "" : s.substr(minStart, minLen);
    }
};