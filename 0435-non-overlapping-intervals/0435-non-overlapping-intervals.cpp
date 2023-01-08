class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by ending time
        sort (intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        
        long lastEnd = (long)INT_MIN-1, ans = 0;
        for (auto & in : intervals) {
            if (lastEnd > in[0]) ++ans;
            else lastEnd = in[1];
        }
        
        return ans;
    }
};