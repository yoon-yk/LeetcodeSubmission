class Solution {
public:
    int minCost(string colors, vector<int>& t) {
        int n = colors.size(), ans = 0;
        for (int i=0, j, sum, maxV; i<n; i=j) {
            j = i, sum = 0, maxV = t[i];
            while (j<n && colors[i] == colors[j]) {
                sum += t[j], maxV = max(maxV, t[j]), ++j;
            }
            ans += (sum - maxV);
        }
        return ans;
    }
};