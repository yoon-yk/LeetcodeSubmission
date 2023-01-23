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
        
        priority_queue<ppair, vector<ppair>, greater<ppair>> pq;

        for (int i=0; i<n; ++i) pq.push({-1, i});
        
        int idx = 0;
        for (auto & m : meetings) {
            while (pq.top().first < m[0]) {
                pq.push({m[0], pq.top().second});
                pq.pop();
            } 
            
            auto [startT, room] = pq.top(); pq.pop();
            pq.push({startT+m[1]-m[0], room});
            ++cnt[room];
            
            if (cnt[room] > cnt[maxFreqIdx] ||
               (cnt[room] == cnt[maxFreqIdx] && (room < maxFreqIdx))) {
                maxFreqIdx = room;
            }
        }

        return maxFreqIdx;
    }
};