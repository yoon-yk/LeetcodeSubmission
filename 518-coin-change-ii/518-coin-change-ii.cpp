class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int coinCnt = coins.size();
        vector<vector<int>> memo (coinCnt, vector<int>(amount+1, 0));
        
        for (int i=0; i<coinCnt; i++) { // coin 
            memo[i][0] = 1;
            for (int j=1; j<=amount; j++) { // amount 
                if (i > 0) memo[i][j] = memo[i-1][j];
                
                if (j-coins[i] < 0) continue;
                memo[i][j] += memo[i][j-coins[i]];

            }
        }
        
        return memo[coinCnt-1][amount];
    }

};