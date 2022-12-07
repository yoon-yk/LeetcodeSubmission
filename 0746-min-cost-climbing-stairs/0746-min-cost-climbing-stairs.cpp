class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        int prevFirst = 0, prevSec = 0, cur = 0;
        for (int i=2; i<=n; ++i) {
            cur = min(cost[i-2] + prevSec, cost[i-1] + prevFirst);
            prevSec = prevFirst;
            prevFirst = cur;
        }
        return cur;
    }
};