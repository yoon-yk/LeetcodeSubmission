class Solution {
public:
    vector<int> countBits(int n) {
        // 0 ~ n, number of 1 in its binary form
        // 0 -> 0 = 0
        // 1 -> 1 = 1 // log(2)1 < 1
        // 2 -> 10 = 1 // log(2)2 = 1
        // 3 -> 11 = 2
        // 4 -> 100 = 1 // log(2)4 = 2
        // 5 -> 101 = 2
        // 6 -> 110 = 2
        // 7 -> 111 = 3
        // 8 -> 1000 = 1
        // 9 -> 1001
        // 10 -> 1010
        // 11 -> 1011
        // 12 -> 
        
        vector<int> ans(n+1, 0);
        int len = 0, cnt;
        for (int i=0; i<=n; i++) {
            cnt = 0;
            for (int j=0; j<floor(log2(i))+1; j++) {
                if (i & (1 << j)) cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};