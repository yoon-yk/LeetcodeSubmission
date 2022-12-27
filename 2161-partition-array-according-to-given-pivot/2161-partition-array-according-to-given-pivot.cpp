class Solution {
public:
    void partition(vector<int>& nums, int pivot) {
        vector<int> less, more;
        int equal = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] < pivot) less.push_back(i);
            else if (nums[i] == pivot) ++equal;
            else more.push_back(i);
        }
        int idx = 0;
        vector<int> ans(nums.size());
        for (auto & i : less) ans[idx++] = nums[i];
        for (int i=0; i<equal; ++i) ans[idx++] = pivot;
        for (auto & i : more) ans[idx++] = nums[i];
        nums.swap(ans);
    }
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        partition(nums, pivot);
        
        return nums;
    }
};