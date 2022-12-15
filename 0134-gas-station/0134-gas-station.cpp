class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int remaining = 0;
        int minIdx = 0, minVal = INT_MAX;
        for (int i=0; i<n; ++i) {
            remaining += gas[i] - cost[i];
            if (remaining < minVal) {
                minIdx = i, minVal = remaining;
            }
        }
        return (remaining < 0) ? -1 : (minIdx + 1) % n;
    }
};