class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret1, ret2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int p1 = 0, p2 = 0, tmp;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] == nums2[p2]) {
                tmp = nums1[p1];
                while (p1 < nums1.size() && nums1[p1] == tmp) ++p1;
                while (p2 < nums2.size() && nums2[p2] == tmp) ++p2;
            } else if (nums1[p1] < nums2[p2]) {
                tmp = nums1[p1];
                ret1.push_back(nums1[p1]);
                while (p1 < nums1.size() && nums1[p1] == tmp) ++p1;
            } else {
                tmp = nums2[p2];
                ret2.push_back(nums2[p2]);
                while (p2 < nums2.size() && nums2[p2] == tmp) ++p2;
            }
        } 

        while (p1 < nums1.size()) {
            tmp = nums1[p1];
            ret1.push_back(nums1[p1]);
            while (p1 < nums1.size() && nums1[p1] == tmp) ++p1;
        }
        
        while (p2 < nums2.size()) {
            tmp = nums2[p2];
            ret2.push_back(nums2[p2]);
            while (p2 < nums2.size() && nums2[p2] == tmp) ++p2;
        }
        
        
        return {ret1, ret2};
    }
};