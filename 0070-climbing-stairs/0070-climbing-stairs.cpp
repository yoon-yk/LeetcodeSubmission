class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> dp(n+1, -1);
        return backtrack(n, dp);
    }
    
    int backtrack(int left, vector<int>& dp){
        
        if (left < 0) return 0;
        if (left == 0) return dp[left] = 1;
        
        if (dp[left] != -1) return dp[left];
        
        int ans = 0;
        ans += backtrack(left-1, dp);
        ans += backtrack(left-2, dp);
        
        return dp[left] = ans;
    }
};