class Solution {
public:
    int countSubstrings(string s) {
        
        int ans = 0;
        for (int i=0; i<s.size(); ++i) {
            ans += check(i, i, s);
            ans += check(i, i+1, s);
        }
        return ans;
    }
    
    int check(int start, int end, string &s) {
        int cnt = 0;
        while (start>=0 && end < s.size() && s[start] == s[end]) {
            start --, end ++, cnt++;
        }
        return cnt;
    }
};