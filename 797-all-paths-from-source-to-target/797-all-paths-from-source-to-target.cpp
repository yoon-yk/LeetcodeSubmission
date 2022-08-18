class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int src = 0, des = graph.size()-1;
        vector<int> curPath;
        vector<vector<int>> ans;
        curPath.push_back(0);
        bfs(0, des, graph, curPath, ans);
        
        return ans;
    }
    
    void bfs(int cur, int des, vector<vector<int>>& graph, vector<int>& curPath, vector<vector<int>>& ans) {
        
        if (cur == des) {
            ans.push_back(curPath);
        } else {
            for (int i : graph[cur]) {
                curPath.push_back(i);
                bfs(i, des, graph, curPath, ans);
                curPath.pop_back();
            }
        }
    }
};