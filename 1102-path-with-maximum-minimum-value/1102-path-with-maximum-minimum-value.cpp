/*

[5,0,3,5,4,1]
[3,5,1,1,2,5]
[3,5,5,5,4,0]
[2,0,3,0,5,5]
[1,4,5,0,0,5]

*/

class Solution {
public:
    vector<int> parent, size;
    int base = 1000;
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    void unionn(pair<int, int> a, pair<int, int> b) {
        int v1 = a.first*base + a.second, v2 = b.first*base + b.second;
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return;
        
        if (size[p1] < size[p2]) {
            size[p2] += size[p1];
            parent[p1] = parent[p2];
        } else {
            size[p1] += size[p2];
            parent[p2] = parent[p1];
        }
    }
    
    bool isValid (vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            return false;
        return true;
    }
    
    int maximumMinimumPath(vector<vector<int>>& grid) {
        parent.resize(100105);
        size.resize(100105, 1);
        for (int i=0; i<parent.size(); ++i) parent[i] = i;
        
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i=0; i<grid.size(); ++i) {
            for (int j=0; j<grid[0].size(); ++j) {
                pq.push({grid[i][j], {i, j}});
            }
        }
        
        int target = (grid.size()-1)*base + (grid[0].size()-1);
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int ans = INT_MAX;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!pq.empty() && find(0) != find(target)) {
            auto cur = pq.top().second; 
            ans = pq.top().first;
            // cout << pq.top().first << endl;
            pq.pop();
            visited[cur.first][cur.second] = true;
            for (int d=0; d<4; ++d) {
                int newI = cur.first+dir[d], newJ = cur.second+dir[d+1];
                if (isValid(grid, newI, newJ) && visited[newI][newJ]) {
                    unionn(cur, {newI, newJ});
                }
            }
        }
        
        return ans;
    }
};