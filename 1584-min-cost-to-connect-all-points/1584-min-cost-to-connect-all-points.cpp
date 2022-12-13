class Solution {
public:
    using pPair = pair<int, int>;
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        priority_queue<pPair, vector<pPair>, greater<pPair>> pq;
        pq.push(pair(0, 0));
        
        int n = points.size();
        vector<int> visited(n, false);
        
        int edge = 0, dist, ans = 0;
        while (!pq.empty() && edge < n) {
            auto cur = pq.top(); pq.pop();
            int curIdx = cur.second, curDist = cur.first;
            if (visited[curIdx]) continue;
            visited[curIdx] = true;
            edge++;
            ans += curDist;
            
            for (int nextIdx=0; nextIdx<n; ++nextIdx) {
                if (visited[nextIdx]) continue;
                dist = abs(points[curIdx][0]-points[nextIdx][0]) + abs(points[curIdx][1]-points[nextIdx][1]);
                pq.push({dist, nextIdx});
            }
        }
        return ans;
    }
};