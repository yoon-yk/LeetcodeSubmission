class Solution {
public:
    int MOD = 1e9 + 7;

    int countOrders(int n) {
        long long ans = 1;
        /*
        (2 * n)! / (2^n)
        */
        for (int i = 1; i <= n; ++i) {
            
            ans = (ans * (i % MOD) /* ((2*i)/2)% MOD == i % MOD */ 
                    * ((2 * i) - 1) % MOD) % MOD;
        }
        return (int) ans;
    }

};