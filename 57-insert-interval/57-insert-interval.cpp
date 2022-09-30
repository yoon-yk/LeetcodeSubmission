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
        
        int idx = 0, end = 0;
        int rangeL = newInterval[0], rangeR = newInterval[1];
        
        while (idx < intervals.size() && intervals[idx][1] < newInterval[0])
            res.push_back(intervals[idx++]);
        
        while (idx < intervals.size() && newInterval[1] >= intervals[idx][0]){
            rangeL = min(rangeL, intervals[idx][0]);
            rangeR = max(rangeR, intervals[idx][1]);
            idx ++;
        }
        
        res.push_back({rangeL, rangeR});

        while (idx < intervals.size())
            res.push_back(intervals[idx++]);

        return res;
    }
};