class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int idx = lower_bound(intervals.begin(), intervals.end(), toBeRemoved) - intervals.begin();
        
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> ans;
        for (; i<idx; i++) 
            ans.push_back(intervals[i]);

        if (i > 0 && ans[i-1][1] > toBeRemoved[0]) {
            int prevEnd = ans[i-1][1];
            ans[i-1][1] = toBeRemoved[0];
            if (prevEnd > toBeRemoved[1]) {
                ans.push_back({toBeRemoved[1], prevEnd});;
            }
        } 
        
        while (i < n && toBeRemoved[1] > intervals[i][0]) {
            if (toBeRemoved[1] < intervals[i][1]){
                ans.push_back({toBeRemoved[1], intervals[i][1]});
                i++;
                break;
            }
            i++;
        }
        
        for (; i<n; i++)
            ans.push_back(intervals[i]);
            
        
        return ans;
    }
};