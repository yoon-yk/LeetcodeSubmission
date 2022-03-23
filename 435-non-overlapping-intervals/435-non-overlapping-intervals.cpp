class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ret, curEnd = 0, delN = 0;
        sort(intervals.begin(), intervals.end());
        for (auto i:intervals)
            printf("[%d,%d],", i[0], i[1]);
        printf("\n");
        
        for (int i=1; i<intervals.size(); i++) {
            printf("i : %d, curEnd : %d\n", i, curEnd);
            if (intervals[i][0] < intervals[curEnd][1]) { // e.g. [1,5] [4,7]
                curEnd = (intervals[curEnd][1] < intervals[i][1])? curEnd : i; 
                delN++;
            } else { // e.g. [0,2] [2,4]
                curEnd = i;
            }
        }
        
        return delN;
    }
};