class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        // 1. Sort - O(N log N)
        sort(nums.begin(), nums.end());

        // 2. find the triplet
        for (int i=0; i<nums.size(); ++i) { // O(N * N) = O(N^2)
            if (i > 0 && nums[i] == nums[i-1]) continue;

            // 3. set the target
            int target = nums[i] * -1;
            int lo = i+1, hi = nums.size()-1;
            while (lo < hi) { // terminate if the pointers are crossed // O(N)
                int sum = nums[lo] + nums[hi];

                if (sum == target) {
                    // insert ans
                    ans.push_back({nums[i], nums[lo], nums[hi]});

                    // duplicate 
                    int tmp = lo;
                    while (tmp < nums.size() && nums[tmp] == nums[lo]) ++tmp;
                    lo = tmp;

                } else if (sum < target) {
                    // lo ptr ++ 
                    ++lo;
                } else {
                    // hi ptr --
                    --hi;
                }

            }
        }

        return ans;
    }
};