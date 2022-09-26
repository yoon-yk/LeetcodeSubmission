class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo (coins.size(), vector<int>(amount+1, -1));
        return backtrack(0, amount, coins, memo);
    }
    
    int backtrack(int idx, int amount, vector<int>& coins, vector<vector<int>>& memo) {
        
        if (memo[idx][amount]!= -1)
            return memo[idx][amount];
        
        if (amount == 0) 
            return memo[idx][amount] = 1;
        
        int ans = 0;
        int n = coins.size();
        for (int i=idx; i<n; i++) {
            if (amount - coins[i] < 0) continue;
            amount -= coins[i];
            ans += backtrack(i, amount, coins, memo) ;
            amount += coins[i];
        }
        
        return memo[idx][amount] = ans;
    }
};