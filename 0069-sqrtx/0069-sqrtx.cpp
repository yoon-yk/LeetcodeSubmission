class Solution {
public:
    /*
    1 2 3 4 5 6 7 8 9
    ^               ^
    1 4 9 16 .. 

    */
    int mySqrt(int x) {
        if (x < 2) return x;
        
        int left = 0, right = x>>1;
        int mid;
        long long midSqr;
        int midPower;
        while (left < right) {
            mid = left + (right-left)/2 + 1;
            midSqr = (long)mid*mid;
            if (x < midSqr) right = mid-1;
            else left = mid;
        }
        return left;
    }
};