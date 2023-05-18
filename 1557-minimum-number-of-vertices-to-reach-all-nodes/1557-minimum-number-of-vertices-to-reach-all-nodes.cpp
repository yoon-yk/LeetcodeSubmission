class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> indeg(n);
        for (auto & e : edges) {
            adjList[e[0]].push_back(e[1]);
            ++indeg[e[1]];
        }
        
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            if (indeg[i] == 0) {
                ans.push_back(i);
            }
        }
    
        return ans;
    }
};