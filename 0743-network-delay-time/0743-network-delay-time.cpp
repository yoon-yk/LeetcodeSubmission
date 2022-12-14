class Solution {
public:
    using ppair = pair<int, int>;
    vector<ppair> adj[101];
    
    void dijkstra(vector<int>& signalReceivedAt, int source, int n) {
        priority_queue<ppair, vector<ppair>, greater<ppair>> pq;
        pq.push({0, source});
        
        signalReceivedAt[source] = 0;
        
        while (!pq.empty()) {
            int curNodeTime = pq.top().first;
            int curNode = pq.top().second;
            pq.pop();

            if (curNodeTime > signalReceivedAt[curNode]) continue;
            
            for (auto & [time, nei] : adj[curNode]) {
                if (signalReceivedAt[nei] <= curNodeTime + time) continue;
                signalReceivedAt[nei] = curNodeTime + time;
                pq.push({signalReceivedAt[nei], nei});
            }
        }
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (auto & time : times) {
            int src = time[0], dst = time[1], travelTime = time[2];
            adj[src].push_back({travelTime, dst});
        }
        
        vector<int> signalReceivedAt(n+1, INT_MAX);
        dijkstra(signalReceivedAt, k, n);
        
        int ans = *max_element(signalReceivedAt.begin()+1, signalReceivedAt.end());
        
        return (ans == INT_MAX) ? -1 : ans;
        
    }
};