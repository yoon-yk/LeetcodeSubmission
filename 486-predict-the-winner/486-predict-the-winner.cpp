class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int i=1; i<=n; i++) 
            prefixSum[i] = prefixSum[i-1] + nums[i-1];

        // 내가 더 큰 점수를 갖고 있다면 승리 
        return maxScore(nums, prefixSum, 0, n-1, dp) >= ((float)prefixSum[n] / 2.0); 
    }

    int maxScore(vector<int> nums, vector<int>& prefixSum, int l, int r, vector<vector<int>>& dp) {
        
        if (dp[l][r]!=-1)
            return dp[l][r];

        if (l == r) 
            return dp[l][r] = nums[r];

        int sum = prefixSum[r+1]-prefixSum[l];

        int oppSumWhenPickLeft = maxScore(nums, prefixSum, l + 1, r, dp); // 내가 왼쪽을 골랐을 때 상대방의 최대 점수 
        int oppSumWhenPickRight = maxScore(nums, prefixSum, l, r - 1, dp); // 내가 오른쪽을 골랐을 때 상대방의 최대 점수 

        return dp[l][r] = (sum - min(oppSumWhenPickLeft, oppSumWhenPickRight)); // 내 최대 점수 
    }
};
