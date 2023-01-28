class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ans = nums[0];
        int prevMin = nums[0], prevMax = nums[0], curMin, curMax;
        for (int i=1; i<n; ++i) {
            curMin = min({prevMin*nums[i], prevMax*nums[i], nums[i]});
            curMax = max({prevMin*nums[i], prevMax*nums[i], nums[i]});
            ans = max(ans, curMax);
            prevMin = curMin, prevMax = curMax;
        }
        return ans;
    }
};