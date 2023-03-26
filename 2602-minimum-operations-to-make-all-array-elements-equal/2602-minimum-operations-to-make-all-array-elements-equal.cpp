class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());
        vector<long long> ls(nums.size()), rs(nums.size());
        long long lps = 0, rps = 0;
        for (int i=0; i<nums.size(); ++i) {
            lps += nums[i], rps += nums[nums.size()-1-i];
            ls[i] = lps;
            rs[nums.size()-1-i] = rps;
        }
        long long lb, ub;
        long long left = 0, right = 0;
        vector<long long> ans;
        
        for (auto & q : queries) {
            q = (long long) q;
            lb = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            ub = upper_bound(nums.begin(), nums.end(), q) - nums.begin();
            
            left = (lb > 0) ? (q * lb) - ls[lb-1] : 0;
            right = (ub < nums.size()) ? rs[ub] - (q * (nums.size()-ub)) : 0;
            
            ans.push_back(left + right);
        }
        
        return ans;
    }
};