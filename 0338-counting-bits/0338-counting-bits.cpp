class Solution {
public:
    /*
    0000  0 0
    0001  1 1
    0010  2 1
    0011  3 2
    /////////
    0100  4 1
    0101  5 2
    0110  6 2
    0111  7 3
    /////////
    1000  8 1
    1001  9 2
    1010 10 2
    1011 11 3
    1100 12 2
    
    */
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for (int i=1; i<=n; i++) {
            ans[i] = ans[i>>1] + (i & 1);
        }
        
        return ans;
    }
};