class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp; // val : cnt
        mp[0] = 1;
        int n = nums.size(), ans = 0, ps = 0, target;
        for (int i=0; i<n; ++i) {
            ps += nums[i];
            target = ps - goal;
            ans += mp[target];
            ++mp[ps];
        }
        return ans;
    }
};