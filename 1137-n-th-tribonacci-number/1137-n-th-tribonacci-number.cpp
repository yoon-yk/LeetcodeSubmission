class Solution {
public:
    int trib[4];
    int tribonacci(int n) {
        trib[0] = 0, trib[1] = trib[2] = 1;
        for (int i=3; i<=n; ++i) {
            trib[i%3] = trib[0] + trib[1] + trib[2];
        }
        return trib[n % 3];
    }
};