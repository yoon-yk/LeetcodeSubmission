class Solution {
public:
    /*
    
    3
    [[0,7],[1,5],[2,5],[3,5],[5,7],[6,7],[7,8],[8,10]]
    
    0 | (0)[0,7] (5)[7,8]
    1 | (1)[1,5] (3)[5,7]
    2 | (2)[3,5] (4)[6,7] 
    
    
    */
    using ppair = pair<long long, int>;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> cnt(n, 0);
        sort(meetings.begin(), meetings.end());
        int maxFreqIdx = 0;
        
        priority_queue<int, vector<int>, greater<int>> avail;
        priority_queue<ppair, vector<ppair>, greater<ppair>> busy;

        for (int i=0; i<n; ++i) avail.push(i);
        
        int room; long long endT, startT;
        for (auto & m : meetings) {
            
            while (!busy.empty() && busy.top().first <= m[0]) {
                avail.push(busy.top().second);
                busy.pop();
            } 
            
            if (!avail.empty()) { 
                room = avail.top(); avail.pop();
                endT = m[1];
            } else {
                endT = busy.top().first + m[1]-m[0]; 
                room = busy.top().second; busy.pop();
            }
            busy.push({endT, room});
            ++cnt[room];
            if (cnt[room] > cnt[maxFreqIdx] ||
               (cnt[room] == cnt[maxFreqIdx] && (room < maxFreqIdx))) {
                maxFreqIdx = room;
            }
        }

        return maxFreqIdx;
    }
};