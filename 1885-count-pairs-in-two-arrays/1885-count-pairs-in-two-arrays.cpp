class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {
        // nums1[i] + nums1[j] > nums2[i] + nums2[j].
        // nums1[i] - nums2[i] > nums2[j] - nums1[j].
        // nums1[i] - nums2[i] > - (nums1[j] - nums2[j]).
        // ans[i] > - ans[j]
        // ans[i] + ans[j] > 0

        /*
        n1 :  2  1  2  1
        n2 :  1  2  1  2
        -----------------
        re :  1 -1  1 -1  
        re : -1  1 -1  1

        */
        int n = nums1.size();
        long long cnt = 0;
        vector<int> ans(nums1.size());
        for (int i=0; i<n; ++i) {
            ans[i] = (nums1[i] - nums2[i]);
        }
        sort(ans.begin(), ans.end());
        
        for (int i=0; i<n; ++i) {
            // cur + counter > 0
            // counter > 0-cur
            // counter >= 0-cur+1
            // counter >= 1-cur
            int idx =  lower_bound(ans.begin(), ans.begin()+i, 1-ans[i]) - ans.begin();
            cnt += i - idx;
        }
        return cnt;
    }
};