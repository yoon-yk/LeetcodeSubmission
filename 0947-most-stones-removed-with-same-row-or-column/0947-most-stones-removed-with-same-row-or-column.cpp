class Solution {
public:
    
    int shareSameRowOrCol(vector<int>& a, vector<int>& b) {
        return a[0] == b[0] || a[1] == b[1];
    }
    
    void dfs (vector<vector<int>>& stones, vector<int> adj[], vector<int>& visited, int src) {
        visited[src] = 1;
        
        for (int & adjc : adj[src]) {
            if (visited[adjc] == 0)
                dfs(stones, adj, visited, adjc);
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        
        vector<int> adj[stones.size()];
        for (int i=0; i < stones.size(); i++) {
            for (int j=i+1; j<stones.size(); j++) {
                if (shareSameRowOrCol(stones[i], stones[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        
        vector<int> visited(stones.size(), 0);
        int componentCount = 0;
        for (int i=0; i<stones.size(); i++) {
            if (visited[i] == 0) {
                componentCount ++;
                dfs (stones, adj, visited, i);
            }
        }
        
        return stones.size() - componentCount;
    }
};