class Solution {
public:
    using ppair = pair<int, int>;
    int minMeetingRooms(vector<vector<int>>& ins) {
        map<int, int> mp;
        for (auto & in : ins) {
            ++mp[in[0]], --mp[in[1]];
        }
        
        int max = 0, cur = 0;
        for (auto &[v, f] : mp) {
            cur += f;
            if (max < cur) max = cur;
        }
     
        return max;
    }
};