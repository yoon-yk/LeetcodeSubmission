class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), minN;
        for (int i=1; i<n; i++) {
            for (int j=0; j<n; j++) {
                minN = matrix[i-1][j]; 
                if (j>0) minN = min(minN, matrix[i-1][j-1]);
                if (j<n-1) minN = min(minN, matrix[i-1][j+1]);
                matrix[i][j] += minN;
            }
        }
        
        int ans = INT_MAX;
        for (int j=0; j<n; j++) 
            ans = min(ans, matrix[n-1][j]);
        
        return ans;
    }
};