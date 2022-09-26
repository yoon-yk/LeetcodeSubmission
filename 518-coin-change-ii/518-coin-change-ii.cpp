class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int coinCnt = coins.size();
        vector<int> memo (amount+1, 0);
        
        memo[0] = 1;
        
        for (int i=0; i<coinCnt; i++) { // coin 
            for (int j=1; j<=amount; j++) { // amount                 
                if (j-coins[i] >= 0) 
                memo[j] += memo[j-coins[i]];

            }
        }
        
        return memo[amount];
    }

};