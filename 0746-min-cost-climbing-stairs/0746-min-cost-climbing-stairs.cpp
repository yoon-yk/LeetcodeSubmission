class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
   
        int choice, prev_2 = cost[0], prev_1 = cost[1];
        for (int i=2; i<cost.size(); i++) {
            choice = min(prev_1, prev_2) + cost[i];            
            prev_2 = prev_1;
            prev_1 = choice;
        }
        
        return min(prev_1, prev_2);
    }
};