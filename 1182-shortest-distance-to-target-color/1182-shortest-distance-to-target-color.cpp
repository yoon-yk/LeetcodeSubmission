class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> arr(3);
        for (int i=0; i<colors.size(); ++i) {
            if (colors[i] == 1) arr[0].push_back(i);
            else if (colors[i] == 2) arr[1].push_back(i);
            else arr[2].push_back(i);
        }

        int idx, col, hi, lo;
        for (auto & q : queries) {
            idx = q[0], col = q[1];
            if (arr[col-1].empty()) {ans.push_back(-1); continue;}
            auto it = lower_bound(arr[col-1].begin(), arr[col-1].end(), idx);
            if (it == arr[col-1].end()) ans.push_back(abs(*prev(it)-idx));
            else if (it == arr[col-1].begin()) ans.push_back(abs(*it-idx));
            else ans.push_back(min(abs(*it-idx), abs(*prev(it)-idx)));
        }
        
        return ans;
    }
};