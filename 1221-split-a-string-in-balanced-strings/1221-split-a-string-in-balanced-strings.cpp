class Solution {
public:
    int balancedStringSplit(string s) {
        int b = 0, ans = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == 'R') ++b;
            else --b;
            if (b == 0) ++ans;
        }
        return ans;
    }
};