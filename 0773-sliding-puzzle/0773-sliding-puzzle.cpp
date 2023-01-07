class Solution {
public:
    vector<vector<int>> dir = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
    
    int kRowSize = 3;
    int slidingPuzzle(vector<vector<int>>& board) {
        int zeroIdx, size, moves = 0;
        string target = "123450";
        string init;
        for (int i=0; i<6; ++i) init += (board[i/kRowSize][i%kRowSize] + '0');
        
        queue<string> Q;
        unordered_set<string> visited;
        visited.insert(init);
        Q.push(init);
        while (!Q.empty()) { 
            size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                if (cur == target) return moves;
                zeroIdx = cur.find('0');

                // slide
                for (auto & d : dir[zeroIdx]) {
                    
                    // swap with zero idx
                    swap(cur[d], cur[zeroIdx]);

                    if (!visited.count(cur)) {
                        visited.insert(cur);
                        Q.push(cur);
                    }
                    // original
                    swap(cur[d], cur[zeroIdx]);
                    
                }
            }
            ++moves;
        }
        return -1;
    }
};