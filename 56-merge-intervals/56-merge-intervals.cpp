class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==1) return intervals;
        
        sort(intervals.begin(), intervals.end(), 
             [](vector<int> a, vector<int> b)->bool{
                 return a[0] < b[0];
             });

        // [1,3], [2,6], [5,9], [8,10]
        vector<vector<int>> res;
        int i=0, j=0, start=i, end=j;
        while (i<=j && (j<intervals.size())) {
            if ((intervals[j][0] <= intervals[end][1]) && 
                   (intervals[j][0] >= intervals[end][0])) {
                end = (intervals[end][1] > intervals[j][1]) ? end : j;
                j++;
            }
            else {
                res.push_back({intervals[start][0], intervals[end][1]});
                i=j; start=i; end=start; j++;
            }
        }
        res.push_back({intervals[start][0], intervals[end][1]});
        return res;
    }
};