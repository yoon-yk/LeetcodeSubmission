class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0; 
        vector<vector<int>> memo(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for (int i = nums1.size()-1; i>=0; --i) {
            for (int j = nums2.size()-1; j>=0; --j) {
                if (nums1[i] == nums2[j]) {
                    memo[i][j] = memo[i+1][j+1] + 1;
                    if (ans < memo[i][j]) ans = memo[i][j];
                }
            } 
        }
        
        return ans;
    }
};