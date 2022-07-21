class Solution {
public:
    bool isPerfectSquare(int num) {
        long long start = 0, end = num, mid;
        while(start < end) {
            mid = (start + end + 1) >> 1;
            if (mid*mid == num) return true;
            if (num < mid*mid) end = mid-1;
            else start = mid;
        }
        return (start == num);
    }
};