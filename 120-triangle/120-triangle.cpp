class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();
        int minN; 
        
        for (int i=1; i<n; i++) {
            for (int j=0; j<=i; j++) {
                minN = INT_MAX;
                if (j > 0) minN = min(minN, triangle[i-1][j-1]);
                if (j < i) minN = min(minN, triangle[i-1][j]);
                triangle[i][j] += minN;
            }
        }
        
        int minPathSum = INT_MAX;
        for (int j=0; j<n; j++)
           minPathSum = min(minPathSum, triangle[n-1][j]);
        
        return minPathSum;
    }
};