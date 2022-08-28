class Solution {
public:
    int rowSize, colSize;
    
    inline void getNext (int &r, int &c){
        r++, c++;
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        rowSize = mat.size(), colSize = mat[0].size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // row first
        int r, c;
        for (int i=0; i < colSize; i++) {
            r = 0, c = i;
            // collect
            while (r < rowSize && c < colSize) {
                pq.push(mat[r][c]);
                getNext(r, c);
            }
            
            // replace
            r = 0, c = i;
            while (!pq.empty()) {
                mat[r][c] = pq.top(); pq.pop();
                getNext(r, c);
            }
        }
            
        // column first (Except for the first row && first col)
        for (int i=1; i < rowSize; i++) {
            r = i, c = 0;
            // collect
            while (r < rowSize && c < colSize) {
                pq.push(mat[r][c]);
                getNext(r, c);
            }
            
            // replace
            r = i, c = 0;
            while (!pq.empty()) {
                mat[r][c] = pq.top(); pq.pop();
                getNext(r, c);
            }
        }
        
        return mat;
    }
};