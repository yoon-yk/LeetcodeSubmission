class Solution {
public:
    int concatenatedBinary(int n) {
    
        const int MOD = 1e9+7;

        long result = 0;
        int length = 0;

        for (int i=1; i<=n; i++) {
            if (ceil(log2(i)) == floor(log2(i)))
                length++;
            
            result = ((result * (int)pow(2, length)) + i) % MOD;
        }
        return result;
    }
};

/*
1 10 11 100 101
*/