class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        vector<int> startTime(n), endTime(n);
        
        for (int i=0; i<n; i++) {
            startTime[i] = intervals[i][0];
            endTime[i] = intervals[i][1];
        }
        
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());

        int startPtr = 0, endPtr = 0;
        
        int cnt = 0;
        while (startPtr < n) {
            if (startTime[startPtr] >= endTime[endPtr]) {
                endPtr++;
            } else {
                cnt++;
            }
            startPtr ++;
        }
        
        return cnt;
    }
};