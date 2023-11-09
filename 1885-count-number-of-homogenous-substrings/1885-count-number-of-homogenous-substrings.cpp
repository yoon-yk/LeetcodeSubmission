
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countHomogenous(string str) {
        int n = str.size();
        int ans = 0, als = 0, s = 0;
        vector<int> cnt(26);
        for (int e = 0; e < n; ++e) {
            int cur = str[e] - 'a';
            ++cnt[cur];
            if (cnt[cur] == 1) ++als;
            if (als > 1) {
                cnt[str[s] - 'a'] = 0;
                s = e;
                --als;
            }
            ans = (ans + cnt[cur]) % MOD;
        }

        return ans;
    }
};