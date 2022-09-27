class Solution {
public:
    string pushDominoes(string dominoes) {
        // bfs
        int n = dominoes.size();
        vector<int> currStatus(n, -1), nextStatus(n, -1);

        /*
        status :   -1 = undecided,
                    0 = balanced, 
                    1 = left, 
                    2 = right 
                    
                    
                    R  R   .  L
                    2, 2, -1, 1 cnt = 3
                           0    cnt = 4
                           
                   .  L  .  R  .  .  .  L  R  .  .  L  .  .
                   -1 1  -1 2 -1 -1 -1  1  2 -1 -1  1 -1 -1 cnt = 5
                   1     0     2     1       2   1          cnt = 6
                                  0                         cnt = 7
                                                            cnt = 7
                   
                   
        */
        
        int prevCnt = 0, curCnt = 0;
        for (int i = 0; i<n; i++) {
            if (dominoes[i] == '.') continue;
            if (dominoes[i] == 'L') {
                currStatus[i] = 1;
            } else if (dominoes[i] == 'R') {
                currStatus[i] = 2;
            }
        }
        
        bool isChanged = true;
        nextStatus = currStatus;

        while (isChanged) { // TODO : if no change in one loop = end of the loop
            isChanged = false;
            
            for (int i=0; i<n; i++) {
                // left most , right most handling
                if (currStatus[i] != -1) continue;
                if (i > 0 && i < n-1 && currStatus[i-1] == 2 && currStatus[i+1] == 1) {
                    nextStatus[i] = 0;
                    isChanged = true;
                }
                else if (i < n-1 && currStatus[i+1] == 1) { // righthand side pushed left
                    nextStatus[i] = 1;
                    isChanged = true;
                }
                else if (i > 0 && currStatus[i-1] == 2) { // // lefthand side pushed left
                    nextStatus[i] = 2;
                    isChanged = true;
                }
            }
            currStatus = nextStatus;
        }
        
        for (int i=0; i<n; i++) {
            if (dominoes[i]!= 'L' && currStatus[i] == 1) {
                dominoes[i]= 'L';
            } else if (dominoes[i]!= 'R' && currStatus[i] == 2) {
                dominoes[i]= 'R';
            } 
        }
        
        return dominoes;
    }
};