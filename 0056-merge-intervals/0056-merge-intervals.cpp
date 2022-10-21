class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto & interv : intervals) {
            if (ans.empty() || ans.back()[1] < interv[0])
                ans.push_back(interv);
            else {
                ans.back()[1] = max(ans.back()[1], interv[1]);
            }
        }
        
        return ans;
    }
};