class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
	int n = size(e);
	vector<vector<int>> graph(n+1);
	vector<bool> vis(n+1);                
	for(auto& E : e) {
        fill(begin(vis), end(vis), false);     // reset the vis array
        graph[E[0]].push_back(E[1]), graph[E[1]].push_back(E[0]);
        if(isCycleDetected(graph, vis, E[0])) return E;
    }
	return { };    // un-reachable
}
    bool isCycleDetected(vector<vector<int>>& graph, vector<bool>& vis, int cur, int par = -1) {
        if(vis[cur]) return true;    // reached already visited node -  cycle detected
        vis[cur] = true;
        for(auto& child : graph[cur]) 
            if(child != par && isCycleDetected(graph, vis, child, cur)) return true;
        return false;    // no cycle found
    }
};