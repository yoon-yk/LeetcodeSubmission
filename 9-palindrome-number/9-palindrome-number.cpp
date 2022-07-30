class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long origN = x, reversedN = 0;
        while (origN > 0) {
            reversedN = reversedN*10 + origN%10 ;
            origN /= 10;
        }
        return (x == reversedN);
    }
};