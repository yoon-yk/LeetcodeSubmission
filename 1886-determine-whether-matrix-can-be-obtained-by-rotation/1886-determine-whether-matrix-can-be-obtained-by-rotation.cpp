class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int cnt = 0;
        while (cnt++ < 4) {
            rotate90(mat);
            if (mat == target) return true;
        }
        return false;
    }
    
    void rotate90(vector<vector<int>>& mat) {
        int n = mat.size();
        
        // transpose
        for (int i=0; i<n; i++)
            for (int j=i; j<n; j++)
                swap(mat[i][j], mat[j][i]);
        
        // reverse 
        for (int i=0; i<n; i++)
            for (int j=0; j<(n>>1); j++) 
                swap(mat[i][j], mat[i][n-1-j]);
    }
};