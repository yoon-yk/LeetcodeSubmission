class Solution {
public:
    vector<vector<int>> cache;
    int endingMask;
    
    int dp(int node, int mask, vector<vector<int>>& graph) {
    
        //First, check if this state has already been visited. If it has, return the cached result.
        if (cache[node][mask] != 0)
            return cache[node][mask];
    

        // Base case - mask only has a single "1", which means
        // that only one node has been visited (the current node)
        if ((mask & (mask-1)) == 0)
            return cache[node][mask] = 0;
            
        
        cache[node][mask] = INT_MAX-1; // Avoid infinite loop in recursion
        
        for (int& neighbor : graph[node]) {
            if ((mask & (1<<neighbor)) != 0) {
                int alreadyVisited = dp(neighbor, mask, graph);
                int notVisited = dp(neighbor, mask ^ (1 << node), graph);
                int betterOption = min (alreadyVisited, notVisited);
                cache[node][mask] = min(cache[node][mask], 1+betterOption);
            }
        }
        
        return cache[node][mask];            
    }
    
    int shortestPathLength(vector<vector<int>>& graph) {    
        int n = graph.size();
        endingMask = (1<<n) -1; // a bitmask that represents all nodes being visited.
        cache.resize(n+1, vector<int>(endingMask+1, 0));
        
        int best = INT_MAX;
        for (int node = 0; node <n; node++)
            best = min(best, dp(node, endingMask, graph));
        
        
        // for (int i=0; i<=n; i++) {
        //     for (int j=0; j<=endingMask; j++) {
        //         cout << cache[i][j] << " ";
        //     }
            // cout << endl;
        // }
        
        return best;
        
    }
};