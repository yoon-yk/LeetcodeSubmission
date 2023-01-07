class Solution {
public:
    int getMin(vector<int>& arr, int idx, int col, vector<vector<int>>& dp) {
        int left = idx, right = idx+1, dist = 0, ans;
        int lMin = INT_MAX, rMin = INT_MAX;
        while (left >= 0) {
            if (dp[idx][col-1] == -1) break;
            else if (dp[idx][col-1] != INT_MAX) {
                lMin = dp[idx][col-1] + dist;
                break;
            } else if (arr[left] == col) {
                lMin = dist;
                break;
            }
            --left, ++dist;
        }
        dist = 1;
        while (right < arr.size() && dist < lMin) {
            if (dp[idx][col-1] == -1) break;
            else if (dp[idx][col-1] != INT_MAX) {
                rMin = dp[idx][col-1] + dist;
                break;
            } else if (arr[right] == col) {
                rMin = dist;
                break;
            }
            ++right, ++dist;
        }
        ans = min(lMin, rMin);
        return dp[idx][col-1] = (ans == INT_MAX ? -1 : ans);
    }
    
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<int> ans;
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        int idx, col;
        for (auto & query : queries) {
            idx = query[0], col = query[1];
            ans.push_back(getMin(colors, idx, col, dp));
        }
        
        return ans;
    }
};