class Solution {
public:
    int subtractProductAndSum(int n) {
        int num = n, digit;
        int prod = 1, sum = 0;
        while (num > 0) {
            digit = num % 10;
            num /= 10;
            prod *= digit, sum += digit;
        }
        return prod-sum;
    }
};