class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> startTimes, endTimes;
        for (auto & in : intervals) {
            startTimes.push(in[0]);
            endTimes.push(in[1]);
        }
        
        /*
        0  5  15
        10 20 30
        */
        int usedRooms = 0;
        while (!startTimes.empty()) {
            if (startTimes.top() >= endTimes.top()) {
                usedRooms --;
                endTimes.pop();
            }
            usedRooms ++;
            startTimes.pop();
        }
        return usedRooms;
    }
};