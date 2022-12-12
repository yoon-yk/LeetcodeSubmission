class Solution {
public:
    
    /*
    1011
    1010
    
    1001
    1000
    0001
    0000
    
    */
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n!=0) {
            cnt += 1;
            n = n & (n-1);
        }
        return cnt;
        
    }
};