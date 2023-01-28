class Solution {
public:
    using ppair = pair<int, pair<int, int>>;
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        priority_queue<ppair, vector<ppair>, greater<ppair>> Q; // cost, {today, idx}
        Q.push({0, {1, 0}});
        
        vector<int> d = {1, 7, 30};
        vector<int> minCost(400, INT_MAX);
        minCost[1] = 0;
        
        int nextDay, nextIdx;
        while (!Q.empty()) {
            auto [cost, info] = Q.top(); Q.pop();
            auto &[day, idx] = info;
            // cout << cost << "/" << day << "/" << idx << endl;
            
            if (day > days.back()) return cost;
            
            if (day < days[idx] && minCost[day+1] > cost) {
                Q.push({cost, {day+1, idx}});
                minCost[day+1] = cost;
            }
            
            for (int i=0; i<d.size(); ++i) {
                nextDay = day + d[i];
                if (minCost[nextDay] <= cost + costs[i]) continue;
                nextIdx = lower_bound(days.begin(), days.end(), nextDay) - days.begin();
                minCost[nextDay] = cost+costs[i];
                Q.push({cost+costs[i], {nextDay, nextIdx}});
            }
            
        }
        
        return -1;
        
    }
};