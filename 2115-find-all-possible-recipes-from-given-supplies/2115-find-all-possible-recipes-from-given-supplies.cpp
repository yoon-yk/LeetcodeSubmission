class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingred, vector<string>& supplies) {
        // topological sort
        vector<string> ans;
        unordered_set<string> dict(recipes.begin(), recipes.end());
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> adjList;
        // indegree 
        for (int i=0; i<recipes.size(); ++i) {
            for (int j=0; j<ingred[i].size(); ++j) {
                adjList[ingred[i][j]].push_back(recipes[i]);
            }
            indegree[recipes[i]] = ingred[i].size();
        }
        
        queue<string> Q;
        for (auto & s : supplies) Q.push(s);
        
        int size;
        while (!Q.empty()) {
            size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                if (dict.count(cur)) ans.push_back(cur);
                
                for (auto& next : adjList[cur]) {
                    if (--indegree[next] == 0) {
                        Q.push(next);
                    }
                }
            }
        }
        
        return ans;
    }
};