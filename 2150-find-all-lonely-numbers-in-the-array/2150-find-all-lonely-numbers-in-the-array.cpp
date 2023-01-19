class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            int j = i;
            while (j+1<n && nums[j+1]-nums[j] <= 1) ++j;
            if (i==j) ans.push_back(nums[i]);
            i = j;
        }
        return ans;
    }
};