class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int std = n*2;
        vector<int> cntNum(n+1, std);
        
        for (int i=0; i<n; i++) {
            --std;
            for (int j=0; j<n; j++) {
                if (--cntNum[matrix[i][j]] < std) return false;
            }
            
            --std;
            for (int j=0; j<n; j++) {
                if (--cntNum[matrix[j][i]] < std) return false;
                
            }
        }
        
        return true;
    }
    
};