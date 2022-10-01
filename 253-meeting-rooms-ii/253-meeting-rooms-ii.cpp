class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        /*
        
        [[7,10],[2,4],[5,8]]
        => [[2,4],[5,8],[7,10]]
        [2,4]
        */
        
        priority_queue<int, vector<int>, greater<int>> rooms;
        sort(intervals.begin(), intervals.end());
        
        int top = INT_MAX;
        for (auto& interval : intervals) {
            if (!rooms.empty()) top = rooms.top();
            if (top <= interval[0]) {
                rooms.pop();
            }
            rooms.push(interval[1]);
        }
        
        return rooms.size();
    }
};