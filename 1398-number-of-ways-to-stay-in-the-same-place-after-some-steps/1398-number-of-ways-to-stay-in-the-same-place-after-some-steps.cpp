class Solution {
public:
    const int MOD = 1e9 + 7;

    int numWays(int steps, int arrLen) {

        // You can't go further than steps/2
        int ARRLEN = min(steps / 2 + 1, arrLen); 
        
        vector<int> prev(ARRLEN, 0), curr(ARRLEN, 0);
        prev[0] = 1; // Base case: one way to be at 0 without any steps.

        for (int s = 1; s <= steps; s++) {
            for (int loc = 0; loc < ARRLEN; loc++) {
                curr[loc] = prev[loc]; // Stay
                if (loc > 0) {
                    curr[loc] = (curr[loc] + prev[loc - 1]) % MOD; // Left
                }
                if (loc < ARRLEN - 1) {
                    curr[loc] = (curr[loc] + prev[loc + 1]) % MOD; // Right
                }
            }
            prev = curr; // Save current state as previous for the next iteration
        }
        return prev[0];
    }
};