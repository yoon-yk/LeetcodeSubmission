class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 0, hi = num, mi;
        while (lo <= hi) {
            mi = lo + ((hi-lo) >> 1);
            if (mi == sqrt(num)) {
                return true;
            } else if (mi < sqrt(num)) {
                lo = mi+1;
            } else {
                hi = mi-1;
            }
        }
        return false;
    }
};