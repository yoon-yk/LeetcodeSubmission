class Solution {
public:
    
    
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>&  dp) {
        if (i == nums1.size() || j == nums2.size()) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        return dp[i][j] = 
            max({nums1[i] * nums2[j] + solve(i + 1, j + 1, nums1, nums2, dp), 
                solve(i + 1, j, nums1, nums2, dp), 
                solve(i, j + 1, nums1, nums2, dp)});
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int firstMax = INT_MIN, secondMax = INT_MIN;
        int firstMin = INT_MAX, secondMin = INT_MAX;
        
        for (int & num: nums1) {
            firstMax = max(firstMax, num);
            firstMin = min(firstMin, num);
        }
        
        for (int & num: nums2) {
            secondMax = max(secondMax, num);
            secondMin = min(secondMin, num);
        }
        
        if (firstMax < 0 && secondMin > 0) {
            return firstMax * secondMin;
        }
        
        if (firstMin > 0 && secondMax < 0) {
            return firstMin * secondMax;
        } 

        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(0, 0, nums1, nums2, dp);
    }
};