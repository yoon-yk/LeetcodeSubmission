class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();        
        /*
        0 0 3 4 4
        */
        int lo = 0, hi = nums.size(), mi, res;
        while (lo <= hi) {
            mi = lo + ((hi-lo) >> 1);
            res = lower_bound(nums.begin(), nums.end(), mi) - nums.begin();
            if (mi == n-res) return mi;
            else if (mi < n-res) lo = mi+1;
            else hi = mi-1;
        }
        return -1;
    }
};