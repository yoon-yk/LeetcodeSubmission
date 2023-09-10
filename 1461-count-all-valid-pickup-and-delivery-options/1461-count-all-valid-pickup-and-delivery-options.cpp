class Solution {
public:
    int MOD = 1e9 + 7;

    int countOrders(int n) {
        long ans = 1;
        for (int i = 1; i <= (n << 1); ++i) {
            ans = (ans * i) % MOD;
            if (i % 2 == 0) {
                ans = (ans * modInverse(2, MOD)) % MOD;
            }
        }
        return (int) ans;
    }

    // multiplicative inverse using Fermat's Little Theorem
    long modInverse(int a, int m) {
        return pow(a, m - 2, m);
    }

    // a^b under modulo m
    long pow(long a, long b, long m) {
        long result = 1;
        a = a % m;
        while (b > 0) {
            if (b % 2 == 1)
                result = (result * a) % m;
            a = (a * a) % m;
            b /= 2;
        }
        return result;
    }

};