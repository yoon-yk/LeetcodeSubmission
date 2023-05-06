class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int N = nums.size();
        int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        
        vector<int> power(N);
        power[0] = 1;
        for (int i=1; i<N; ++i) {
            power[i] = (power[i-1] * 2) % MOD;
        }
        
        int answer = 0;
        
        for (int left = 0; left < N; ++left) {
            int right = prev(upper_bound(nums.begin(), nums.end(), target-nums[left])) - nums.begin();
            if (right >= left) {
                answer += power[right-left];
                answer %= MOD;
            }
        }
        
        return answer;
    }
};