class Solution {
public:
    
    bool check (vector<int>& target, vector<int>& board) {
        for (int i=0; i<6; i++) 
            if (target[i]!=board[i])
                    return false;
        return true;
    }
    
    int findZeroPos (vector<int>& board) {
        int i = 0;
        for (i=0; i<6; i++) {
            if (board[i] == 0)
                break;
        }
        return i;
    }
    
    vector<int> matrixToArray (vector<vector<int>>& board) {
        vector<int> newArray;
        for (int i=0; i<2; i++)
            for (int j=0; j<3; j++)
                newArray.push_back(board[i][j]);
        return newArray;
    }
    
    inline int getIdx(int r, int c) {
        return (r*3) + c;
    }
    
    inline int visHashing(vector<int> arr) {
        int ret = 0;
        for (int i=0; i<6; i++) {
            ret += ((i*arr[i]+777) << arr[i]*2) + (i<<arr[i]);
        }
        return ret;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        
        vector<int> target = {1,2,3,4,5,0};
        vector<int> dir = {-1, 0, 1, 0, -1};
        vector<int> curBoard = matrixToArray(board);
        if (check(target, curBoard)) return 0;
        
        unordered_set<int> visited;
        queue<vector<int>> Q;
        
        Q.push(curBoard);
        visited.insert(visHashing(curBoard));
        
        int moveCnt = 0;
        while(!Q.empty()) {
            int sizeQ = Q.size();

            while (sizeQ--) {
                auto cur = Q.front(); Q.pop();

                if (check(target, cur))
                    return moveCnt;
                
                int zeroPos = findZeroPos (cur);
                int nextIdx, curHashed;
                int r = zeroPos/3, c = zeroPos % 3;

                for (int d = 0; d < 4; d++) {
                    if (r+dir[d] < 0 || r+dir[d] > 1 || c+dir[d+1] < 0 || c+dir[d+1] > 2) continue;
                    nextIdx = getIdx(r+dir[d],c+dir[d+1]);

                    swap(cur[zeroPos], cur[nextIdx]);
                    
                    curHashed = visHashing(cur);
                    if (visited.find(curHashed)!=visited.end()) {
                        swap(cur[zeroPos], cur[nextIdx]);
                        continue;
                    }


                    Q.push(cur);

                    
                    visited.insert(curHashed);
                    swap(cur[zeroPos], cur[nextIdx]);
                    
                }
                
            }
            moveCnt++;
        }
        
        return -1;
        
    }
};