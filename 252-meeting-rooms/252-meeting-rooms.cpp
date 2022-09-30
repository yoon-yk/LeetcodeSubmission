class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        //  determine if a person could attend all meetings.
        // --> check if there's any overlapping
        
        sort(intervals.begin(), intervals.end());
        
        int prevEnd = 0;
        for (auto & interval : intervals) {
            if (interval[0] < prevEnd)
                return false;
            prevEnd = interval[1];
        }
        
        return true;
    }
};