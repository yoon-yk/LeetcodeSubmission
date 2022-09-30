class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = lower_bound(intervals.begin(), intervals.end(), newInterval) - intervals.begin();
        
        int n = intervals.size();

        for (int i=0; i<idx; i++) {
            ans.push_back(intervals[i]);
        }
        
        if (idx > 0 && ans.back()[1] >= newInterval[0]) {
            ans.back()[1] = max(ans.back()[1], newInterval[1]);
        } else {
            ans.push_back(newInterval);
        }
        
        for (int i=idx; i<n; i++) {
            if (ans.empty() || ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else {
                ans.push_back(intervals[i]);
            }
        }
    
        return ans;    
    }
};