class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b(n);
        string s = b.to_string();
        reverse(s.begin(), s.end());
        bitset<32> bb(s);
        return bb.to_ulong();
    }
};