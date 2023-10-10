class Solution {
public:
    int minOperations(vector<int>& nums) {
        // diff between max elem - min elem == (nums.len - 1)
        // 2 3 4 5
        // 1 2 3 4

        int n = nums.size(), ans = n;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            int lo = nums[i], hi = lo + n - 1;
            // up => greater
            int j = upper_bound(nums.begin(), nums.end(), hi) - nums.begin();
            ans = min(ans, n-(j-i));
        }

        return ans;
    }
};