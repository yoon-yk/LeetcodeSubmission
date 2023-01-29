class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxLen = 1;
        vector<int> len(n, 1), cnt(n, 1);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j] >= nums[i]) continue;                    
                if (len[i] == len[j]+1) {
                    cnt[i] += cnt[j];
                } else if (len[i] < len[j]+1) {
                    cnt[i] = cnt[j];
                    len[i] = len[j] + 1;
                }
            }
            if (len[i] > maxLen) {
                maxLen = len[i];
                ans = cnt[i];
            } else if (len[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};