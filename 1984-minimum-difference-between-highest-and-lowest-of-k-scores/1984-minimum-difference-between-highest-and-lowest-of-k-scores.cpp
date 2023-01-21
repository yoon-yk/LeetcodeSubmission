class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        /*
        1, 4, 7, 9
        */
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int end=k-1; end<nums.size(); ++end) {
            ans = min(ans,(nums[end]-nums[end-k+1]));
        }
        return ans;
    }
};