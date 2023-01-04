class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int target = 1;
        vector<int> ans;
        for (int i=0, j; i<nums.size(); ++target) {
            if (nums[i] != target) ans.push_back(target);
            else while (i<nums.size() && nums[i] == target) ++i;
        }
        for (; target <= nums.size(); ++target) ans.push_back(target);
        
        return ans;
    }
};