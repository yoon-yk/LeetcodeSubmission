class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i=0; i<n; i++) {
            if (toBeRemoved[0] > intervals[i][1] || toBeRemoved[1] < intervals[i][0]) {
                ans.emplace_back(intervals[i]);
            } else {
                if (intervals[i][0] < toBeRemoved[0]) {
                    ans.push_back({intervals[i][0], toBeRemoved[0]});
                }
                if (intervals[i][1] > toBeRemoved[1]) {
                    ans.push_back({toBeRemoved[1], intervals[i][1]});    
                }
            }
        } 
        
        return ans;
    }
};