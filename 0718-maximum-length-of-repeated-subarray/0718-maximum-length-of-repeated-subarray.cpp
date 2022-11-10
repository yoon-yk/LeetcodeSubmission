class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        
        vector<int> cur(len2+1, 0), prev(len2+1, 0);
        int maxVal = 0;
        for (int i=len1-1; i>=0; i--) {
            for (int j=len2-1; j>=0; j--) {
                if (nums1[i] == nums2[j]) {
                    cur[j] = prev[j+1] + 1;
                    if (maxVal < cur[j] ) 
                        maxVal = cur[j];
                } else cur[j] = 0;
            }
            cur.swap(prev);
        }
        
        return maxVal;
    }
};