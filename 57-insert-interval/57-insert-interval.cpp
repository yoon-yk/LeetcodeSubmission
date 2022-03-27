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
        
        int start = 0, end = 0;
        int rangeL = newInterval[0], rangeR = newInterval[1];
        while(start < intervals.size() && intervals[start][1] < newInterval[0]){
            res.push_back(intervals[start++]);
            end = start;
        }
        while(end < intervals.size() && newInterval[1] >= intervals[end][0]){
            rangeL = min(rangeL, intervals[start][0]);
            rangeR = max(rangeR, intervals[end][1]);
            end ++;
        }
        res.push_back({rangeL, rangeR});
        while(end < intervals.size()){
            res.push_back(intervals[end++]);
        }       
        return res;
    }
};