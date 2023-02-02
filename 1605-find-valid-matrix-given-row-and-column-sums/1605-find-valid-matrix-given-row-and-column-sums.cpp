class Solution {
public:
    int rSize, cSize;
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        rSize = rowSum.size(), cSize = colSum.size();
        vector<vector<int>> ret(rSize, vector<int>(cSize));
        if (backtrack(rSize-1, cSize-1, rowSum, colSum, ret)) return ret;
        return {};
    }
    
    bool backtrack(int r, int c, vector<int>& rowSum, vector<int>& colSum, vector<vector<int>>& ret) {
        
        if (r == -1) return true;
        
        for (int v = min(rowSum[r], colSum[c]); v >= 0; --v) {
            if (r == 0 && colSum[c] != v) continue;
            if (c == 0 && rowSum[r] != v) continue;
            
            rowSum[r] -= v, colSum[c] -= v;
            ret[r][c] = v;
            
            if (c == 0) { // last element of the row
                if (backtrack(r-1, cSize-1, rowSum, colSum, ret)) 
                    return true; 
                // filled all row 
            } else {
                if (backtrack(r, c-1, rowSum, colSum, ret)) 
                    return true;
            }
            
            rowSum[r] += v, colSum[c] += v;
        }
        return false;
        
    }
};