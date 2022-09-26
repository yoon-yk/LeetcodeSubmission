class Solution {
    public:
        int coinChange(vector < int > & coins, int amount) {
            vector <int> tb(amount + 1, 0);
            return dp(coins, tb, amount);
        }
    
    int dp(vector < int > & coins, vector < int > & tb, int n) {
        if (n < 0) return -1;
        if (n == 0) return 0;
        if (tb[n]) return tb[n];
        int tmp = INT_MAX;
        
        for (auto i = coins.begin(); i != coins.end(); i++) {
            int local = dp(coins, tb, n - * i);
            if (local == -1) continue;
            tmp = min(tmp, 1 + local);
        }
        if (tmp == INT_MAX) {
            return tb[n] = -1;
        }
        return tb[n] = tmp;
    }
};