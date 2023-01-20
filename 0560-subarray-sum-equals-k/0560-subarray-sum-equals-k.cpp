class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*
        cur-target = k
        target = cur-k
        */
        int ans = 0, ps = 0, target;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i=0; i<nums.size(); ++i) {
            ps += nums[i];
            ans += mp[ps - k];
            ++mp[ps];
        }
        return ans;
    }
};