class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int equal = 0, less = 0, more = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] < pivot) ++less;
            else if (nums[i] == pivot) ++equal;
            else ++more;
        }
        int lIdx = 0, eIdx = less, mIdx = less + equal;
        vector<int> ans(nums.size());
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] < pivot) ans[lIdx++] = nums[i];
            else if (nums[i] == pivot) ans[eIdx++] = nums[i];
            else ans[mIdx++] = nums[i];
        }
        nums.swap(ans);
        return nums;
    }
};