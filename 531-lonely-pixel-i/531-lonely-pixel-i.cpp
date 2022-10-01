class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        /*
                row  col
        black    0    2
                 1    1
                 2    0
        */
        
        int n = picture.size(), m = picture[0].size();
        vector<int> rowValid(n, -1), colValid(m, -1);
                
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++) {
                                
                if (picture[i][j] == 'B') {
                    
                    if (rowValid[i] != -1) {
                        rowValid[i] = 0;
                    } else rowValid[i] = 1;
                    
                    if (colValid[j] != -1) {
                        colValid[j] = 0;
                    } else colValid[j] = 1;
                }                
            }
        }
        
        int cnt = 0;
        
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++) {
                if (picture[i][j] == 'B' && rowValid[i] && colValid[j]) {
                    cnt++;
                }
            }
        }
        
        return cnt;
        
    }
};