class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();

        // Make sure len(nums1) > len(nums2) to optimize space
        if (nums1.size() < nums2.size()) return findLength(nums2, nums1); 
        
        int ans = 0; 
        vector<int> prev(n2+1, 0);
        vector<int> cur(n2+1);
        
        for (int i = 1; i<=n1 ; i++) {
            for (int j = 1; j<=n2; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    cur[j] = prev[j-1] + 1;
                    if (ans < cur[j]) ans = cur[j];
                } else cur[j] = 0;
            } 
            prev.swap(cur);
        }
        
        return ans;
    }
};