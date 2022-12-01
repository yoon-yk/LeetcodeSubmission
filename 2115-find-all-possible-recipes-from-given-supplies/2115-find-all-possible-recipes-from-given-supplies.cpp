// 17:21

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        // recipes
        // ingredients
        // supplies
        
        // topological sort
        // starting from supplies
        
        // making graph
        // yeast -> bread (indeg++)
        // flour -> bread (indeg++)
        // bread -> sandwich (indeg++)
        // meat -> sandwich (indeg++)
        
        // << BFS using Q >>
        // starting from bread and sandwich
        // for its next node, --indeg;
        // if its next node's indeg == 0;
        // push it to queue
        
        // everytime a node goes into Q, check if it's in a recipes. 
        // If so, push it to answer
        
        
        // bread = 0, sandwich = 1;
        // yeast = 2, flour = 3
        // meat = 4, 
        
        unordered_map<string, int> nodes; // name and node #;
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> indeg;
        
        int idx = 0;
        
        for (; idx<recipes.size(); idx++)
            nodes[recipes[idx]] = idx;
        
        int curNode;
        for (int rec=0; rec<ingredients.size(); rec++) {
            for (int j=0; j<ingredients[rec].size(); j++) {
                if (nodes.count(ingredients[rec][j]))
                    curNode = nodes[ingredients[rec][j]];
                else {
                    curNode = idx++;
                    nodes[ingredients[rec][j]] = curNode;
                }
                
                adjList[curNode].push_back(rec);
                indeg[rec]++;
            }
        }
        
        
        queue<int> Q;
        for (auto & sp : supplies) 
            if (nodes.count(sp)) Q.push(nodes[sp]);
        
        
        vector<string> ret;
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            if (cur < recipes.size()) {
                ret.push_back(recipes[cur]);
            }
            
            for (auto & next : adjList[cur]){
                if (--indeg[next] == 0)
                    Q.push(next);
            }
        }
        
        return ret;
        
    }
};