class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        
        vector<long long> ps;
        long long s = 0;
        for (int i=0; i<nums.size(); ++i) {
            s += nums[i];
            ps.push_back(s);
        }
        
        // 1 3 6 8
        
        long long idx;
        long long ret;
        vector<long long> ans;
        for (auto & q : queries) {
            q = (long long) q;
            idx = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            ret = (2 * idx * q) + s - (nums.size() * q);
            if (idx > 0) ret -= 2 * ps[idx-1];
            ans.push_back(ret);
        }
        return ans;
    }
};