class Solution {
public:
    int climbStairs(int n) {
        int stairs[3] = {0, 1, 2};
        for (int i=3; i<=n; i++)
            stairs[i%3] = stairs[(i-1)%3] + stairs[(i-2)%3];
        
        return stairs[n%3];
    }
};