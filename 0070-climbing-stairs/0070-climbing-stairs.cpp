class Solution {
public:
    int climbStairs(int n) {
        int third = 1, second = 1, now = 1;
        for (int i=2; i<=n; ++i) {
            now = third + second;
            third = second;
            second = now;
        }
        return now;
        
    }
};