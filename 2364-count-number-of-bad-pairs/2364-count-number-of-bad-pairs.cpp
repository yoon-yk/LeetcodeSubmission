class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        /*
        j - nums[j] != i - nums[i]
        */
        int n = nums.size(); 
        for (int i=0; i<n; ++i) {
            nums[i] = i-nums[i];
        }
        
        sort(nums.begin(), nums.end());
        
        long long int ans = 0;
        for (int i=0; i<n; ++i) {
            ans += (n-(upper_bound(nums.begin(), nums.end(), nums[i])- nums.begin()));
        }
        
        return ans;
    }
};