class Solution {
public:
    /*
    1 2 3 4 5 6 7 8 9
    ^               ^
    1 4 9 16 .. 

    */
    int mySqrt(int x) {
        int left = 0, right = x;
        double mid, midSqr;
        int midPower;
        while (left < right) {
            mid = left + (right-left)/2 + 1;
            midSqr = mid*mid;
            if (x < midSqr) right = mid-1;
            else left = mid;
        }
        return left;
    }
};