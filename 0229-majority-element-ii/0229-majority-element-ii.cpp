class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int f = floor(n/(double)3);
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto & n : nums) ++mp[n];
        for (auto & [n, cnt] : mp) {
            if (cnt > f) ans.push_back(n);
        }
        return ans;
    }
};