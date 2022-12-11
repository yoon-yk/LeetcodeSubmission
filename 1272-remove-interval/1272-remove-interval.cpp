class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> result;
        for (auto & in : intervals) {
            if (in[0] > toBeRemoved[1] || in[1] < toBeRemoved[0])
                result.push_back({in[0], in[1]});
            else {
                if (in[0] < toBeRemoved[0])
                    result.push_back({in[0], toBeRemoved[0]});
                if (in[1] > toBeRemoved[1]) 
                    result.push_back({toBeRemoved[1], in[1]});
            }
        }
        return result;
    }
};