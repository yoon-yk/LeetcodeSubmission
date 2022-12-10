class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        
        int r = grid.size(), c = grid[0].size();

        vector<int> curVec = grid[0];
        vector<int> oppVec = grid[0];
        for (int &i : oppVec) i=!i;

        for (int i=1; i<r; ++i) {
            if (grid[i] != curVec && grid[i] != oppVec)
                return false;
        }
        
        return true;
        
    }
};