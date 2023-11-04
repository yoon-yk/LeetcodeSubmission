class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(int steps, int arrLen) {
        int newLim = min(steps/2 + 1, arrLen);

        vector<int> prev(newLim), curr(newLim);
        prev[0] = 1;

        for (int s=1; s<=steps; ++s) {
            for (int loc=0; loc < newLim; ++loc) {
                // stay
                curr[loc] = prev[loc];

                // moving left
                if (loc + 1 < newLim)
                    curr[loc] = (curr[loc] + prev[loc+1]) % MOD;

                // moving right
                if (0 < loc)
                    curr[loc] = (curr[loc] + prev[loc-1]) % MOD;
            }
            prev = curr;
        }

        return prev[0];
    }
};