class Solution {
public:
    int climbStairs(int n) {
        
        if (n < 3) return n;
        
        int prev = 2, secPrev = 1, res;
        for (int i=3; i<=n; i++) {
            res = prev + secPrev;
            secPrev = prev;
            prev = res;
        }
        return res;
    }
};