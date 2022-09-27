class Solution {
public:
    string pushDominoes(string dominoes) {
        // bfs
        int n = dominoes.size();
        queue<int> q;

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
            if (dominoes[i] == '.')
                q.push(i);
        }

        int i, size;
        string cur = dominoes, next = dominoes; 
        while (!q.empty()) { // TODO : if no change in one loop = end of the loop

            size = q.size();
            while (size--) {
                i = q.front(); q.pop();
            
                // left most , right most handling
                if (i > 0 && i < n-1 && cur[i-1] == 'R' && cur[i+1] == 'L') {
                    continue;
                }
                else if (i < n-1 && cur[i+1] == 'L') { // righthand side pushed left
                    next[i] = 'L';
                    if (i > 0 && cur[i-1] == '.') q.push(i-1);
                }
                else if (i > 0 && cur[i-1] == 'R') { // // lefthand side pushed left
                    next[i] = 'R';
                    if (i < n-1 && cur[i+1] == '.') q.push(i+1);
                }
            }
            
            cur = next;

        }
    
        return cur;
    }
};