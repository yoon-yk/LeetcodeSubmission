class Solution {
public:
    int base;
    vector<int> parent, size;
    vector<int> dir = {-1, 0, 1, 0, -1};
    vector<vector<bool>> visited;

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
        
        base = grid[0].size();
        parent.resize(10005);
        size.resize(10005, 1);
        visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int i=0; i<parent.size(); ++i) parent[i] = i;
        
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i=0; i<grid.size(); ++i)
            for (int j=0; j<grid[0].size(); ++j)
                pq.push({grid[i][j], {i, j}});
    
        int target = (grid.size()-1)*base + (grid[0].size()-1);
        
        int ans = INT_MAX;
        while (!pq.empty()) {
            auto [r, c] = pq.top().second; 
            ans = pq.top().first; pq.pop();
            visited[r][c] = true;
            for (int d=0; d<4; ++d) {
                int newI = r+dir[d], newJ = c+dir[d+1];
                if (isValid(grid, newI, newJ) && visited[newI][newJ]) {
                    unionn({r,c}, {newI, newJ});
                    if (find(0) == find(target)) return ans;
                }
            }
        }
        
        return ans;
    }
};