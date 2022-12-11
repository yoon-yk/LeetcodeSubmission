class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto & in : intervals) {
            if (!ans.empty() && ans.back()[1] >= in[0]) {
                ans.back()[1] = max(in[1], ans.back()[1]);
            } else 
                ans.push_back(in);
        }
        
        return ans;
    }
};