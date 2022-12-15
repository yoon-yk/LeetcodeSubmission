class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    bool inRange(vector<vector<int>>& rooms, int i, int j) {
        return (i>=0 && j>=0 && i<rooms.size() && j<rooms[0].size());
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        queue<pair<int, int>>Q;
        for (int i=0; i<rooms.size(); ++i) {
            for (int j=0; j<rooms[0].size(); ++j) {
                if (rooms[i][j] == 0)
                    Q.push({i, j});
            }
        }
        
        int curCost = 0, size;
        while (!Q.empty()) {
            size = Q.size();
            for (int sz=0; sz<size; ++sz) {
                auto [curR, curC] = Q.front(); Q.pop();

                for (int d=0; d<4; ++d) {
                    int nextR = curR+dir[d], nextC = curC+dir[d+1];
                    if (inRange(rooms, nextR, nextC)  && rooms[nextR][nextC] > curCost+1) {
                        rooms[nextR][nextC] = curCost+1;
                        Q.push({nextR, nextC});
                    }
                }
            }
                
            ++curCost;
        }
    }
};