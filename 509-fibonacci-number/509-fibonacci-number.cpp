class Solution {
public:
    int fib(int n) {
        int fibArr[] = {0, 1};
        for (int i=2; i<=n; i++)
            fibArr[i%2] = fibArr[0] + fibArr[1];
        return fibArr[n%2];
    }
};