class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i=0; i<n; ++i) {
            int maxN = nums[i], minN = nums[i];
            for (int j=i; j>=0; --j) {
                maxN = max(nums[j], maxN);
                minN = min(nums[j], minN);
                
                ans = ans + (maxN - minN);     
            }
        }
        return ans;
    }
};