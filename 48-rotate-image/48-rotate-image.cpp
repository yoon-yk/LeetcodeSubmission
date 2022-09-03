class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_map<string, int> hashM;
        
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                hashM[to_string(c)+"/"+to_string(n-r-1)] = matrix[r][c]; 
            }
        }
        
        for (int r=0; r<n; r++) {
            for (int c=0; c<n; c++) {
                matrix[r][c] = hashM[to_string(r)+"/"+to_string(c)];
            }
        }
    }
};