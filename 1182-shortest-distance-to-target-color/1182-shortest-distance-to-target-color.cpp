class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int> rightMost = {0, 0, 0}, leftMost = {n-1, n-1, n-1};
        vector<vector<int>> dist(3, vector<int>(n, -1));
        
        for (int i=0; i<n; ++i) {
            int color = colors[i]-1;
            for (int j=rightMost[color]; j<i+1; ++j) 
                dist[color][j] = i-j;
            rightMost[color] = i+1;
        }
        
        for (int i=n-1; i>-1; --i) {
            int color = colors[i]-1;
            for (int j=leftMost[color]; j>i-1; --j)
                if (dist[color][j] == -1 || dist[color][j] > j-i)
                    dist[color][j] = j-i;
            leftMost[color] = i-1;
        }
        
        vector<int> queryResults;
        for (auto &q : queries) 
            queryResults.push_back(dist[q[1]-1][q[0]]);
        
        return queryResults;
        
    }
};