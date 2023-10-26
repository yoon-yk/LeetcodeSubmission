class Solution {
public:
using ll = long long;
const int MOD  = 1e9 + 7;
int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    unordered_map<ll, ll> cnt;

    /*
     * arr = [2]
     * */
    ll ans = 0;
    for (int i=0; i<arr.size(); ++i) {
        int res = arr[i];
        cnt[res] = 1;
        for (int j=0; j<=i; ++j) {
            int cand = arr[j];
            int target = res / cand;
            if (res % cand != 0 || !cnt.count(target)) continue;
            cnt[res] = (cnt[res] + (cnt[cand] * cnt[target])) % MOD;
        }
        ans = (ans + cnt[res]) % MOD;
    }
    return (int)ans;
}

};