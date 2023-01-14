class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int idx;
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i) {
            idx = abs(nums[i])-1;
            if (nums[idx] < 0) ans.push_back(idx+1);
            else nums[idx] *= -1;
        }
        return ans;
    }
};