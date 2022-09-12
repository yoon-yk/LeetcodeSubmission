class Solution {
 public:
  int cycleStart = -1;
bool *cycle, *vis, found{};
void dfs(vector<int> graph[], int cur, int par = -1) {
	if(vis[cur]) { cycleStart = cur; found = true; return; }   
	vis[cur] = true;                                        
	for(auto child : graph[cur]) {                          
		if(child == par) continue;                          
		if(!found) dfs(graph, child, cur);     
		if(cycleStart != -1) cycle[cur]=true;  
		if(cur == cycleStart) { cycleStart = -1; return; } 
	}
}
vector<int> findRedundantConnection(vector<vector<int>>& e) {
	int n = size(e);
	vector<int> graph[n+1];
	cycle = (bool*)calloc(n+1, sizeof(bool));
    vis = (bool*)calloc(n+1, sizeof(bool));
	for(auto& edge : e) graph[edge[0]].push_back(edge[1]), graph[edge[1]].push_back(edge[0]);
	dfs(graph, 1);   
	for(int i = n-1; ~i; i--)
		if(cycle[e[i][0]] && cycle[e[i][1]]) return e[i];  
	return { };    
}
};