class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());        
        
        /*
        0 5 10 15 20 30
        0 ---------- 30
          5-10
               15-20
        ===============
        1 1 -1 1  -1  -1
        1 2 1  2   1   0
        
        */
        map<int, int> maxRooms;
        for (auto & in : intervals) {
            maxRooms[in[0]] ++, maxRooms[in[1]] --;
        }
    
        int ans = 0;
        int prefixSum = 0;
        for (auto & i : maxRooms) {
            prefixSum += i.second;
            ans = max(prefixSum, ans);
        }
        
        return ans;
    
    }
};