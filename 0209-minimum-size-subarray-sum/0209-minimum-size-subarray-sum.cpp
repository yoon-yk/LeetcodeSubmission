class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int start = 0, ans = n+1, sum = 0;
        for (int end=0; end<n; ++end){
            sum += nums[end];
            
            while (sum >= target) {
                sum -= nums[start];
                ans = min(ans, end-start+1);
                ++start;
            }
        }
        return (ans == n+1) ? 0 : ans;
    }
};