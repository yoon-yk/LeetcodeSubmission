class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        
        int maxLen = 0;
        backtrack(0, 0, nums1, nums2, dp, maxLen);
        // for (int i=0; i<=n1; i++) {
        //     for (int j=0; j<=n2; j++) 
        //         printf("%2d ", dp[i][j]);
        //     cout << endl;
        // }
        
        return maxLen;
    }
    
    int backtrack(int idx1, int idx2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp, int &maxLen) {
                
        if (dp[idx1][idx2]!= -1)
            return dp[idx1][idx2];
        
        if (idx1>= nums1.size() || idx2>= nums2.size())
            return dp[idx1][idx2] = 0;
        
        int ans = 0;
        
        if (nums1[idx1] == nums2[idx2])
            ans = max(ans, 1 + backtrack(idx1+1, idx2+1, nums1, nums2, dp, maxLen));
        
        int skip1 = backtrack(idx1+1, idx2, nums1, nums2, dp, maxLen);
        int skip2 = backtrack(idx1, idx2+1, nums1, nums2, dp, maxLen);
        
        maxLen = max(maxLen, ans);
        return dp[idx1][idx2] = ans;
    }
};