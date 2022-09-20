class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0; 
        vector<vector<int>> memo(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        for (int i = 0; i<nums1.size() ; i++) {
            for (int j = 0; j<nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    memo[i][j] = (i-1 >= 0 && j-1 >= 0) ? memo[i-1][j-1] + 1 : 1;
                    if (ans < memo[i][j]) ans = memo[i][j];
                }
            } 
        }
        
        return ans;
    }
};