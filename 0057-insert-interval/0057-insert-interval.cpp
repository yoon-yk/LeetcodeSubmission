class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& target) {
        
        // smaller ..... overlap .... greater
        // push_back ... merge ... push_back
        // interval[1] < target[0]
                            // target[1] < interval[0]
        // overlap merge
            // smallest starting point, biggest ending point
        
        int idx = 0;
        vector<vector<int>> ans;
        for (; idx < intervals.size(); ++idx) {
            if (intervals[idx][1] >= target[0]) break;
            else ans.push_back(intervals[idx]);
        }
        
        
        for (; idx < intervals.size(); ++idx) {
            if (target[1] < intervals[idx][0]) break;
            else {
                target[0] = min(intervals[idx][0], target[0]);
                target[1] = max(intervals[idx][1], target[1]);
            }
        }
        ans.push_back(target);
        
        for (; idx < intervals.size(); ++idx) {
            ans.push_back(intervals[idx]);
        }
        
        return ans;
        
    }
};