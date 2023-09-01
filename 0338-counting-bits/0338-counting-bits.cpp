class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n+1);
        for (int i=0; i<=n; ++i) {
            bitset<32> b(i);
            ret[i] = b.count();
        }
        return ret;
    }
};