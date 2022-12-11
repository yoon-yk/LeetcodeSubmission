class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        /*
            3-4
        1---3
          2-3
        1-2
        -------
        1-2-3-4
       <2-2-1-0>
        
        1-2
          2---4
            3-4
            
            
        1------------100
         2-3
           3-4
        */
        
        sort(intervals.begin(), intervals.end(), [](auto &e1, auto &e2) {
            return e1[1] < e2[1];
        });

        int cnt = 0, curEnd = INT_MIN;
        for (auto & in : intervals) {
            if (in[0] < curEnd) cnt++;
            else curEnd = in[1];
        }
        
        return cnt;
    }
};