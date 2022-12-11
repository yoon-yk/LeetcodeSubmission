class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (auto & in : intervals) {
            if (ans.empty() || ans.back()[1] < in[0])
                ans.push_back(in);
            else ans.back()[1] = max(ans.back()[1],in[1]);
        }
        
        return ans;
    }
};