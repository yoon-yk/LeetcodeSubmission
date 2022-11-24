class Lengths{
public:
    int h;
    int v;
    int d;
    int ad;
    
    Lengths(){
        h=v=d=ad=0;
    }
    
    int getMax() {
        return max(h, max(v, max(d, ad)));
    }
};

class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        /*
        
        if (cell is 0) = reset all 4 values to 0 
        else {[i][j-1]+1, [i-1][j]+1, [i-1][j-1]+1, [i-1][j+1]+1}
        maxLen = max(maxLen, mat[i][j]);
        
                // horizontal, vertical, diagonal, anti-di
        0 1 1 0 /// [0,0,0,0] [1,1,1,1] [2,1,1,1] [0,0,0,0]
        0 1 1 0 /// [0,0,0,0] [1,2,1,2] [2,2,2,1]
        0 0 0 1
        */
        
        int n = mat.size(), m = mat[0].size();
        vector<vector<Lengths>> lenMatrix(n, vector<Lengths>(m));
        int ans = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 0) continue;
                
                lenMatrix[i][j].v = (i-1 >= 0) ? lenMatrix[i-1][j].v+1 : 1;
                lenMatrix[i][j].h = (j-1 >= 0) ? lenMatrix[i][j-1].h+1 : 1;

                lenMatrix[i][j].d = (i-1 >= 0 && j-1 >= 0) ? lenMatrix[i-1][j-1].d+1 : 1;
                lenMatrix[i][j].ad = (i-1 >= 0 && j+1 < m)? lenMatrix[i-1][j+1].ad+1 : 1;
                ans = max(ans, lenMatrix[i][j].getMax());

            }
        }
        
        return ans;
        
    }
};