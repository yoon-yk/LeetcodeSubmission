class Solution {
public:
    
    /*
    [1,2],[3,5],[6,7],[8,10],[12,16]
    [7,11]
    
    [1,2],[3,5],[6,7],[7,11],[8,10],[12,16]
    [1,2],[3,5],[6,11],[12,16]

    */
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.size() == 0) return {newInterval};
        
        int idx = 0;
        
        while (idx < intervals.size() && intervals[idx][1] < newInterval[0])
            res.emplace_back(intervals[idx++]);

        int rangeL = newInterval[0], rangeR = newInterval[1];
        if (idx < intervals.size() && intervals[idx][0] < newInterval[0])
            rangeL = intervals[idx][0];
        while (idx < intervals.size() && newInterval[1] >= intervals[idx][0]){
            rangeR = max(rangeR, intervals[idx][1]);
            idx ++;
        }
        
        res.push_back({rangeL, rangeR});

        while (idx < intervals.size())
            res.emplace_back(intervals[idx++]);

        return res;
    }
};