class Solution {
public:

     int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), res = 0, maxLen = 0;
        vector<int> len(n, 1), cnt(n, 1);
         //dp[i]: {length, number of LIS which ends with nums[i]}
         
         
        for (int i = 0; i<n; i++){
            for (int j = 0; j <i ; j++){
                if (nums[i] > nums[j]){
                    if (len[i] == len[j]+ 1)
                        cnt[i] += cnt[j];
                    else if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            
            if (maxLen == len[i])
                res += cnt[i];
            else if (maxLen < len[i]){
                maxLen = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
    
    
};