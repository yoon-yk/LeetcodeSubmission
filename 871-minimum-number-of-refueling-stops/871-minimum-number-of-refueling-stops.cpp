class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& s) {
        priority_queue<int> pq;
        
        int curLoc = startFuel;
        int cnt = 0;        
        int i=0;
        
        while (curLoc < target) {
            while (i<s.size() && s[i][0] <= curLoc)
                pq.push(s[i++][1]);
            if (pq.empty()) return -1;
            curLoc += pq.top(); pq.pop();
            cnt++;
        }
        
        return cnt;
    }
};