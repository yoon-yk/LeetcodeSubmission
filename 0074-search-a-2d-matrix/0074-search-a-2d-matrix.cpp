class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int lo = 0, hi = (n*m)-1, mid, midR, midC;
        while (lo <= hi) {
            mid = (lo + hi) >> 1;
            midR = mid/m, midC = mid%m;
            if (mat[midR][midC] == target)
                return true;
            else if (mat[midR][midC] < target)
                lo = mid+1;
            else hi = mid-1;
        }
        return false;
    }
};