class Node {
public :
    int r;
    int c;
    int curVisit;

    Node (int r, int c, int curVisit) {
        this->r = r, this->c = c, this->curVisit = curVisit;
    };
};

class Solution {
public:
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    
    int shortestPathAllKeys(vector<string>& grid) {
        // get keys only
        // how many keys
        /*
         "@.a..",
         "###.#",
         "b.A.B"
        
        */
        
        int keyCount = 0;
        unordered_set<char> hashSet = {'a', 'b', 'c', 'd', 'e', 'f'};
        unordered_map<int, unordered_map<int, unordered_set<int>>> visited;
        pair<int, int> startIdx = {0, 0};
        
        // know the starting point and number of keys
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == '@') {
                    startIdx.first = i, startIdx.second = j;
                } else if (hashSet.count(grid[i][j])) {
                    keyCount = max(keyCount, grid[i][j]-'a');
                }
            }
        }

        int curVisit = 0;
        int foundKey = (1 << (keyCount+1)) - 1;

        queue<Node*> Q;
        visited[startIdx.first][startIdx.second].insert(0);
        Q.push(new Node(startIdx.first, startIdx.second, curVisit));
    
        int steps = 0;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                int r = cur->r, c = cur->c, curVisit = cur->curVisit; 
                if (0 <= grid[r][c]-'a' && grid[r][c]-'a' <= 6)
                    curVisit |= (1 << (grid[r][c]-'a'));
                if (curVisit == foundKey)
                    return steps;
                
                for (int d=0; d<4; d++) {
                    int newR = r + dir[d], newC = c + dir[d+1];
                    if (!isRangeValid(grid, visited, newR, newC, curVisit)) continue;
                    Q.push(new Node(newR, newC, curVisit));
                    visited[newR][newC].insert(curVisit);

                }
                
            }
            steps += 1;
        }
        
        return -1;
        
    }
    
    bool isRangeValid(vector<string>& grid, unordered_map<int, unordered_map<int, unordered_set<int>>>& visited, int i, int j, int curVisit) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#' || 
           (0 <= grid[i][j]-'A' && grid[i][j]-'A' <= 6 && !(curVisit & (1 << (grid[i][j]-'A')))) || visited[i][j].count(curVisit))
            return false;
        return true;
    }
};