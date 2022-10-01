class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        if (n == 0)  return 0;

        auto compare = [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        };
        
        sort(intervals.begin(), intervals.end(), compare);
        
        int end = intervals[0][1];
        int count = 1;        

        for (auto interval : intervals) {
            if (interval[0] >= end) {
                end = interval[1];
                count++;
            }
        }
        return n - count;
    }
};