class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int i, j;
        int startR = 0, endR = matrix.size()-1;
        int startC = 0, endC = matrix[0].size()-1;
        
        while (startR<=endR && startC<=endC){
            if (res.size()==matrix.size()) break;
            
            for (i=startC; i<=endC; i++)
                res.push_back(matrix[startR][i]);
            startR++;
            
           for (j=startR; j<=endR; j++)
                res.push_back(matrix[j][endC]);
            endC--; 
            
            if (startR <= endR) {
                for (i=endC; i>=startC; i--)
                    res.push_back(matrix[endR][i]);
                endR--;
            }

            if (startC <= endC) {
                for (j=endR; j>=startR; j--)
                    res.push_back(matrix[j][startC]);
                startC++;
            }
            
        }
        
        return res;
    }
};