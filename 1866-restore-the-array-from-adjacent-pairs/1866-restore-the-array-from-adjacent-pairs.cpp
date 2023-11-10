class Solution {
public:
    void dfs(int par, int cur, vector<int>& path, unordered_map<int, unordered_set<int>>& adjList) {

        path.push_back(cur);

        for (auto & nei : adjList[cur]) {
            if (nei == par) continue;
            dfs(cur, nei, path, adjList);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& pairs) {
        int n = pairs.size() + 1;
        unordered_map<int, unordered_set<int>> adjList(n);
        unordered_map<int, int> indeg;

        for (auto & p : pairs) {
            adjList[p[0]].insert(p[1]);
            adjList[p[1]].insert(p[0]);
            ++indeg[p[0]], ++indeg[p[1]];
        }

        int start = 0;
        for (auto & [e, cnt] : indeg) {
            if (cnt == 1) {
                start = e;
                break;
            }
        }

        vector<int> path;
        dfs(1e6, start, path, adjList);
        

        return path;
    }
};