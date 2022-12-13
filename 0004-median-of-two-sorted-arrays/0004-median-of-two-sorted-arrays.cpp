class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // naive
        // merge -> find median
        
        int len1 = nums1.size(), len2 = nums2.size();
        int mid = (len1 + len2) >> 1;
        
        int p1 = 0, p2 = 0;
        int cnt = 0, cur = 0, prev = 0;
        while (cnt <= mid) {
            prev = cur;
            if (p1 < len1 && p2 < len2) {
                if (nums1[p1] < nums2[p2])
                    cur = nums1[p1++];
                else cur = nums2[p2++];
            } else if (p1 < len1) cur = nums1[p1++];
            else cur = nums2[p2++]; 
            cnt++;
        }
        return ((len1 + len2) % 2) ? cur : (cur+prev) * 0.5;
        
        /*
        
        1 3 5
          ^
        2 4 6
          ^
        1 2 3 4 5 6 
            ^
        */
        
        
        
    }
};