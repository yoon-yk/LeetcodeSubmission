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
        int left = 0, right = N-1;
        
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                answer += power[right-left];
                answer %= MOD;
                ++left;
            } else {
                --right;
            }
        }
        
        return answer;
    }
};