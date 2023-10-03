class Solution {
public:
    const int lim = 101;
    /*
    [1,2,3,1,1,3]
    [1,1,1,2,3,3]
    [1 2 3]
    [3 1 2]
    */
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> cnt(lim);
        for (auto & n : nums) {
            ++cnt[n];
        }
        int ans = 0;
        for (int i=0; i<lim; ++i) {
            ans += (cnt[i] * (cnt[i]-1)) / 2;
        }
        return ans;
    }
};