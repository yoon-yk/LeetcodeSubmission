class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for (int i=0; i<=n; i++) {
            int j = i, cnt = 0;
            while (j != 0) {
                cnt ++;
                j &= (j-1);
            }
            ans[i] = cnt;
        }
        return ans;
    }
};