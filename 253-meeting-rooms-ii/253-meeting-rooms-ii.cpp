class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        map<int, int> timeline;
        for (auto &interval : intervals) {
            
            timeline[interval[0]]++;
            timeline[interval[1]]--;
        }
        
        int sum = 0, maxSum = 0;
        for (auto &[time, count] : timeline) {
            sum += count;
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};