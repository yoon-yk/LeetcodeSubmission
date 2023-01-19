class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        long long ps = 0;
        int start = 0, ans = 1;
        for (int end=0; end<n; ++end) {
            ps = (ps + nums[end]);
            
            if ((long)(end-start+1)*nums[end] > ps+k) {
                ps = (ps - nums[start]);
                ++ start;
            }
            
            ans = max(end-start+1, ans);
        }
        return ans;
    }
};