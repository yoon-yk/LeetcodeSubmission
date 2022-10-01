class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        int end = intervals[0][1];
        int count = 0;        

        /*
        [1,5],[1,7],[2,3],[3,4]
        
        [1,5]
        case1) [5,8] // non-overlap - no need to delete
        case2) [1,6] // overlap - discard the new one and keep the one with the smaller end
        case3) [2,3] // overlap - discard the current one and keep 
        */
        
        for (int i=1; i<n; i++) {
            if (intervals[i][0] < end) {
                count++;
                end = min(end, intervals[i][1]);
            } else {
                end = intervals[i][1];
            }
        }
        return count;
    }
};