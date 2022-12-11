class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;
        int start = newInterval[0], end = newInterval[1];
        int i=0;
        for (; i<intervals.size(); ++i) {
            auto & in = intervals[i];
            if (in[1] < newInterval[0] ) {
                ans.push_back(in);
            } else if (in[0] <= newInterval[1]) {
                start = min(start, in[0]);
                end = max(end, in[1]);
            } else break;
        }
        ans.push_back({start, end});
        for (; i<intervals.size(); ++i) {
            auto & in = intervals[i];
            ans.push_back(in);
        }
        return ans;

    }
};