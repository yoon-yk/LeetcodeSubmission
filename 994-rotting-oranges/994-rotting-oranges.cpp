class Solution {
public:
    int dir[5] = {0, -1, 0, 1, 0};
    int orangesRotting(vector<vector<int>>& grid) {
        typedef struct pair<int, pair<int, int>> pos;
        queue<pos> q;
        int rowSize = grid.size(), colSize = grid[0].size();
        int freshN = 0;
        for (int i=0; i<rowSize; i++) {
            for (int j=0; j<colSize; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }else if (grid[i][j] == 1) {
                    freshN++;
                }
            }
        }
        if (freshN == 0) return 0;
        
        int currR, currC, currStage, finalStage = -1;
        while(!q.empty()){
            pos curr = q.front(); q.pop();
            for (int i=0; i<4; i++) {
                currR = curr.second.first+dir[i];
                currC = curr.second.second+dir[i+1];
                currStage = curr.first + 1;
                if (currR < 0 || currC < 0 || currR >= rowSize || currC >= colSize)
                    continue;
                if (grid[currR][currC] != 1)
                    continue;
                grid[currR][currC] = 2;
                freshN--;
                finalStage = max(currStage, finalStage);
                q.push({currStage, {currR, currC}});
            }
        }
        
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++) {
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
        
        if (freshN > 0) return -1;
        else return finalStage;
    }
};