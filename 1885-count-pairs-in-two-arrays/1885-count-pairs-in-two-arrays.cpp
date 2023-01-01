class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        /*
        [2, 1, 2, 1]
        [1, 2, 1, 2]
        
        nums1[i] + nums1[j] > nums2[i] + nums2[j].
        nums1[i] - nums2[i] > - (nums1[j]-nums2[j])
        
        arr[i] + arr[j] > 0
        a + b > 0
        b > -a
        */
        
        for (int i=0; i<nums1.size(); ++i) {
            nums1[i] -= nums2[i];
        }
        sort(nums1.begin(), nums1.end());

        int target, idx;
        long long ans = 0;
        for (int i=0; i<nums1.size(); ++i) {
            target = (-1) * nums1[i];
            idx = upper_bound(nums1.begin(), nums1.begin()+i, target)-nums1.begin();
            ans += (i-idx);
        }
        
        return ans;
    }
};