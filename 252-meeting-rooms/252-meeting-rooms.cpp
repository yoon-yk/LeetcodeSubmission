class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        //  determine if a person could attend all meetings.
        // --> check if there's any overlapping
        
        sort(intervals.begin(), intervals.end());
        
        int maxEnd = 0;
        for (auto & interval : intervals) {
            if (interval[0] < maxEnd)
                return false;
            maxEnd = interval[1];
        }
        
        return true;
    }
};