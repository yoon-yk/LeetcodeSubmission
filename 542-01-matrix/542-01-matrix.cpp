class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int dir[5] = {0, 1, 0, -1, 0};
        /*
            r, c+1
            r+1, c
            r, c-1
            r-1, c
        */        
        int rowSize = mat.size(), colSize = mat[0].size();
        typedef pair<int, int> pos;
        queue<pos> q;
        
        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                if (mat[row][col] == 0) q.push({row, col});
                else mat[row][col] = -1;
            }
        }
        
        while(!q.empty()){
            pos cur = q.front(); q.pop();
            for (int i=0; i<4; i++) {
                int curR = cur.first + dir[i];
                int curC = cur.second + dir[i+1];
                if (curR < 0 || curC < 0 || curR >= rowSize || curC >= colSize)
                    continue;
                if (mat[curR][curC] != -1)
                    continue;
                mat[curR][curC] = mat[cur.first][cur.second] + 1;
                q.push({curR, curC});
            }
        }
        
        return mat;
    }
    
};