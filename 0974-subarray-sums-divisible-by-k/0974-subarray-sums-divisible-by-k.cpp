class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k, 0);
        cnt[0] = 1;
        long ps = 0;
        int ans = 0;
        for (int i=0; i<nums.size(); ++i) {
            ps += nums[i];
            int d = ((ps % k)+k) % k;
            ans += cnt[d];
            ++cnt[d];
        }
        return ans;
    }
};