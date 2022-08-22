class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        unordered_map<int, int> hashM;
        
        for (int i=1; i < 1000000000; i*=4) 
            hashM[i]++;
        
        while (n%4 == 0 && !hashM.count(n)) n >>= 2;
        
        return (hashM.count(n));
    }
};