class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>> adjList(n);
        for (auto & f : flights) {
            int from = f[0], to = f[1], price = f[2];
            adjList[from].push_back(pair(to, price));
        }
        
        queue<pair<int, int>> Q;
        Q.push(pair(src, 0));
        int ans = INT_MAX, stops = 0;
        
        vector<int> minCost(n, INT_MAX);
        
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                auto& cur = Q.front(); 
                int curLoc = cur.first, curCost = cur.second;
                Q.pop();
                
                if (curLoc == dst){
                    ans = min(ans, curCost);
                    continue;
                }

                for (auto & [nextDes,price] : adjList[curLoc]) {
                    if (minCost[nextDes] < curCost+price) continue;
                    minCost[nextDes] = curCost+price;
                    Q.push(pair(nextDes, curCost+price));
                }

            }
            if (stops++ > k) break;
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};