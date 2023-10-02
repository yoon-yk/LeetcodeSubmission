class Solution {
public:
    bool winnerOfGame(string c) {
        int a = 0, b = 0;
        int n = c.size();
        for (int i=1; i < n-1; ++i) {
            if (c[i-1] != c[i] || c[i] != c[i+1]) continue;
            if (c[i] == 'A') ++a;
            else ++b;
        }
        return a > b;
    }
};