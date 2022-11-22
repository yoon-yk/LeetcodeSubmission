class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        
        int maxLen = 0;
        for (int i=n1-1; i>=0; i--) {
            for (int j=n2-1; j>=0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                    if (maxLen < dp[i][j])
                        maxLen = dp[i][j];
                }
            }
        }
        
        return maxLen;
    }
    
    int backtrack(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int &maxLen) {
                
        if (dp[idx1][idx2]!= -1)
            return dp[idx1][idx2];
        
        if (idx1>= nums1.size() || idx2>= nums2.size())
            return dp[idx1][idx2] = 0;
        
        int ans = 0;
        
        if (nums1[idx1] == nums2[idx2])
            ans = 1 + backtrack(idx1+1, idx2+1, nums1, nums2, dp, maxLen);
        
        int skip1 = backtrack(idx1+1, idx2, nums1, nums2, dp, maxLen);
        int skip2 = backtrack(idx1, idx2+1, nums1, nums2, dp, maxLen);
        
        // ans = max(ans, max(skip1, skip2));
        maxLen = max(maxLen, ans);
        return dp[idx1][idx2] = ans;
    }
};