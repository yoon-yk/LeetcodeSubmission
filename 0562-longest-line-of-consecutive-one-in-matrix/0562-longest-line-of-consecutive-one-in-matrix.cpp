class Lengths{
public:
    int h;
    int v;
    int d;
    int ad;
    
    Lengths(){
        h=v=d=ad=0;
    }
    
    void resetToZero() {
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
        vector<Lengths> curLenMatrix (m), prevLenMatrix(m);
        int ans = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (mat[i][j] == 0) {
                    curLenMatrix[j].resetToZero();
                    continue;
                }
                
                curLenMatrix[j].v = prevLenMatrix[j].v+1;
                curLenMatrix[j].h = (j-1 >= 0) ? curLenMatrix[j-1].h+1 : 1;

                curLenMatrix[j].d = (j-1 >= 0) ? prevLenMatrix[j-1].d+1 : 1;
                curLenMatrix[j].ad = (j+1 < m)? prevLenMatrix[j+1].ad+1 : 1;
                ans = max(ans, curLenMatrix[j].getMax());

            }
            prevLenMatrix = curLenMatrix;
        }
        
        return ans;
        
    }
};