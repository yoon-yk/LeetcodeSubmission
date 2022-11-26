class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        // which row?
        int lr = 0, hr = mat.size()-1;
        while (lr < hr) { // find the lower bound
            int mr = (lr + hr + 1) >> 1;
            if (mat[mr][0] == target) return true;
            if (mat[mr][0] < target) lr = mr;
            else hr = mr-1;
        }
        if (hr == -1) return false;

        // which col?
        int lc = 0, hc = mat[0].size()-1;
        while (lc <= hc) {
            int mc = (lc + hc) >> 1;
            if (mat[hr][mc] == target) return true;
            else if (target < mat[hr][mc]) hc = mc-1;
            else lc = mc+1;
        }

        return false;
    }
};