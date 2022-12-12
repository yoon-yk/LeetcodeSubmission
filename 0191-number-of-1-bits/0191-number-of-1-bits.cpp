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
        bitset<32> i(n);
        return i.count();
    }
};