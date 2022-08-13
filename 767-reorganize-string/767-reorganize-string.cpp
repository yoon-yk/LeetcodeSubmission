class Solution {
public:
    string reorganizeString(string s) {
        
        string ans = "";
        int topCommonCh;
        int maxCnt = INT_MIN;
        vector<int> chars(26, 0);
        
        for (const char& c:s) {
            chars[c-'a']++;
            if (chars[c-'a'] > maxCnt) {
                maxCnt = chars[c-'a'];
                topCommonCh = c-'a';
            }
        }
                
        if ((s.size() + 1) >> 1 < maxCnt) return ans;
        
        int idx = 0;
        vector<char> ret(s.length());
        while (chars[topCommonCh] > 0) {
            ret[idx] = topCommonCh + 'a';
            chars[topCommonCh]--;
            idx += 2;
        }
        
        for (int i=0; i<26; i++) {
            if (chars[i] <= 0) continue;
            while (chars[i] > 0) {
                if (idx >= s.length()) 
                    idx = 1;
                ret[idx] = i + 'a';
                chars[i]--;
                idx += 2;   
            }
        }
        
        for (char ch:ret)
            ans += ch;
        return ans;
    }
};