class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        
        int n = intervals.size();
        vector<vector<int>> ans;
        for (auto & interval : intervals) {
            if (toBeRemoved[0] > interval[1] || toBeRemoved[1] < interval[0]) {
                ans.emplace_back(interval);
            } else {
                if (interval[0] < toBeRemoved[0]) {
                    ans.push_back({interval[0], toBeRemoved[0]});
                }
                if (interval[1] > toBeRemoved[1]) {
                    ans.push_back({toBeRemoved[1], interval[1]});    
                }
            }
        } 
        
        return ans;
    }
};