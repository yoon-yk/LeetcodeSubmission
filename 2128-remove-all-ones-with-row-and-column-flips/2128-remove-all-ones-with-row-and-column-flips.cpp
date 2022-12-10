class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        /*
        0 1 0   0 1 0
        1 0 1   0 1 0
        0 1 0   0 1 0
        
        1 0 0   0 1 1   1 1 1
        0 1 0   0 1 0   1 1 0
        0 0 1   0 0 1   1 0 1
        
        0 0 0   0 1 0   
        0 1 0   0 0 0  
        0 0 0   0 1 0
        
        1 0 1 0 
        1 0 1 0 
        1 0 1 0  
        
        1 0 1 0
        0 1 0 1
        0 1 0 1
        
        1 0 1 0
        0 1 0 1
        1 0 1 0 
        
        0 0 0   0 0 1   1 1 0
        0 0 0   0 0 1   0 0 1
        0 0 0   0 0 1   0 0 1
        
        0 0 0   0 1 0   0 1 0   1 1 1
        0 0 0   0 1 0   1 0 1   0 0 0
        0 0 0   0 1 0   0 1 0   1 1 1
        
        0 0 0   0 1 0
        1 1 1   1 0 1
        0 0 0   0 1 0
        
        0 0 0 0 
        0 0 0 0 
        0 0 0 0 
        
        1 1 1 1 
        0 0 0 0 
        0 0 0 0 
        
        1 0 1 0
        0 1 0 1 
        0 1 0 1  
        
        1 0 1 0
        0 1 0 1
        1 0 1 0
        
        0 1 1 0
        1 0 0 1
        0 1 1 0
        
        0 1 1 0
        1 0 0 1
        1 0 0 1
        
        1 1 0   0 0 1
        
        
        1 1 0   
        1 1 0   
        0 0 1   
        
        */
        
        int r = grid.size(), c = grid[0].size();
        
        int prevOnes = 0;
        int currOnes = 0;
        
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