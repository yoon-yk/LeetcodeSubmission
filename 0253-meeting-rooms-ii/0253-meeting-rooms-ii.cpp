class Solution {
public:
    using ppair = pair<int, int>;
    int minMeetingRooms(vector<vector<int>>& ins) {
        priority_queue<int, vector<int>, greater<int>> starts, ends;
        
        for (auto & in : ins) {
            starts.push(in[0]), ends.push(in[1]);
        }
        
        int ans = 0;
        while (!starts.empty()) {
            auto cur = starts.top(); starts.pop();
            if (ends.top() > cur) ++ans;
            else ends.pop();
        }
     
        return ans;
    }
};