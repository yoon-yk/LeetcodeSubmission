class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
        S1 + S2 = SUM
        DIFF = S2 - S1 (S2 >= S1)
             = (SUM-S1) - S1
             = SUM - 2*S1
             // S1을 최대한으로 만들기 (sum/2 >= S1)
        */
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum>>1;
        vector<vector<int>> dp(stones.size()+1, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i=1; i<=stones.size(); ++i) {
            for (int s=0; s<=target; ++s) {
                dp[i][s] = dp[i-1][s];
                if (s-stones[i-1] >= 0) {
                    dp[i][s] += dp[i-1][s-stones[i-1]];
                } 
            }
        }

        int n = stones.size();
        for (int s=target; s>=0; --s) {
            if (dp[n][s] > 0) return (sum-s*2);
        }
        
        return -1;
    }
};