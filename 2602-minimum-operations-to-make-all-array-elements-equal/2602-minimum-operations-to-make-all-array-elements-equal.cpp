class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        
        sort(nums.begin(), nums.end());
        vector<long long> ls(nums.size());
        long long lps = 0;
        for (int i=0; i<nums.size(); ++i) {
            lps += nums[i];
            ls[i] = lps;
        }
        long long lb, ub;
        long long left = 0, right = 0;
        vector<long long> ans;
        
        for (auto & q : queries) {
            q = (long long) q;
            lb = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            
            left = (lb > 0) ? (q * lb) - ls[lb-1] : 0;
            right = (lb > 0) ? (lps - ls[lb-1]) - (q * (nums.size()-lb)) : lps - (q * (nums.size() - lb));
            
            ans.push_back(left + right);
        }
        
        return ans;
    }
};