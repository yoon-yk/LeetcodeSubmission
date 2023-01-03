class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ins, vector<int>& newI) {
        vector<vector<int>> ans;
        int i = 0;
        for (; i<ins.size(); ++i) {
            if (ins[i][1] < newI[0]) ans.push_back(ins[i]);
            else break;
        }
        
        while(i<ins.size() && ins[i][0] <= newI[1]) {
            newI[0] = min(ins[i][0], newI[0]);
            newI[1] = max(ins[i][1], newI[1]);
            ++i;
        }
        ans.push_back(newI);
        
        for (;i<ins.size(); ++i) ans.push_back(ins[i]);
        
        return ans;
    }
};