class Solution {
public:
    vector<pair<int, int>> adj[101];
    
    void DFS(vector<int>& signalReceivedAt, int currNode, int currTime) {
        if (currTime>=signalReceivedAt[currNode])
            return;
        
        signalReceivedAt[currNode] = currTime;
        
        for (auto & edge : adj[currNode]) {
            int travelTime = edge.first;
            int neighborNode = edge.second;
            
            DFS(signalReceivedAt, neighborNode, currTime+travelTime);
        }
    }   
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (vector<int>& time : times) {
            int src = time[0];
            int dst = time[1];
            int travelTime = time[2];
            
            adj[src].push_back({travelTime, dst});
        }
        
        for (int i=1; i<=n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        
        vector<int> signalReceivedAt(n+1, INT_MAX);
        DFS(signalReceivedAt, k, 0);
        
        int ans = *max_element(signalReceivedAt.begin()+1, signalReceivedAt.end());
        return (ans == INT_MAX) ? -1 : ans;
    }
};