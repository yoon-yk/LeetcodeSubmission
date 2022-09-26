class Solution {
  public:
    int helper(vector < int > & coins, int amount, int n, vector < vector < int >> & h) {
      if (amount == 0) return 0;
      if (n < 0 || amount < 0) return INT_MAX - 1;
      if (h[n][amount] != -1) return h[n][amount];
        
      h[n][amount] = min(helper(coins, amount, n - 1, h), 
                        helper(coins, amount - coins[n], n, h) + 1);
        
      return h[n][amount];
    }

  int coinChange(vector < int > & coins, int amount) {
    vector<vector<int>> h (coins.size() + 1, vector <int>(amount + 1, -1));
      
    int ans = helper(coins, amount, coins.size() - 1, h);
      
    return (ans < INT_MAX - 1) ? ans : -1;
  }
};