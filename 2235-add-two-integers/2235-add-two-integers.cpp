class Solution {
public:
    int sum(int num1, int num2) {
        /*
        12 = 1100
         5 = 0101
        */
        int sign = 1;
        if (num1 < 0 && num2 < 0) {sign = -1; num1*=-1, num2*=-1;}
        return sign * ((num1 ^ num2) + ((num1 & num2) << 1));
    }
};