class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int coinCnt = coins.size();
        vector<vector<int>> memo (coinCnt, vector<int>(amount+1, 0));
        
        memo[0][0] = 1;
        for (int i=0; i<coinCnt; i++) { // coin 
            for (int j=0; j<=amount; j++) { // amount 
                if (i > 0) memo[i][j] = memo[i-1][j];
                if (j-coins[i] >= 0) 
                memo[i][j] += memo[i][j-coins[i]];

            }
        }
        
        return memo[coinCnt-1][amount];
    }

};