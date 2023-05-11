class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp (n1+1, vector<int> (n2+1, -1));
        int ans = solve(0, 0, nums1, nums2, dp);
        return ans;
        
    }
    
    int solve(int id1, int id2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        
        if (id2 == nums2.size()) {
            return 0;
        }
        
                
        if (dp[id1][id2] != -1) {
            return dp[id1][id2];
        }
        
        int ans = 0;
        for (int i=id1; i<nums1.size(); ++i) {
            if (nums1[i] == nums2[id2]) {
                ans = max(ans, solve(i+1, id2+1, nums1, nums2, dp) + 1);
            }
        }
        
        ans = max(ans, solve(id1, id2+1, nums1, nums2, dp));

        
        return dp[id1][id2] = ans;
    }

};