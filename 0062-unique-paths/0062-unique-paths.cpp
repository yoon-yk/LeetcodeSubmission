class Solution {
public:
    int comb(int n, int k) {
        long long result = 1;
        
        // k 만큼 곱하기
        // 분자 (n, n-1, ..., n-k+1)
        // 분모 (1, 2, ..., k) 
        for (int i = 1; i <= k; ++i) {
            result *= (n - i + 1);
            result /= i;
        }
        
        return (int)result;
    }

    int uniquePaths(int m, int n) {
        return comb(m-1+n-1, min(m-1, n-1));
    }
};