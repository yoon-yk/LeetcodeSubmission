class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        vector<int> minn(n), maxx(n);
        minn[0] = maxx[0] = nums[0];
        for (int i=1; i<n; ++i) {
            minn[i] = min({minn[i-1]*nums[i], maxx[i-1]*nums[i], nums[i]});
            maxx[i] = max({minn[i-1]*nums[i], maxx[i-1]*nums[i], nums[i]});
            ans = max(ans, maxx[i]);
        }
        return ans;
    }
};