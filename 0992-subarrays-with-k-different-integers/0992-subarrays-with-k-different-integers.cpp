class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1); 
    }
    
    int atMostK(vector<int>& nums, int k) {
        unordered_map<int, int> used;
        int n = nums.size(), start = 0, ans = 0;
        for (int end=0; end<n; ++end) {
            ++used[nums[end]];
            
            while (used.size() > k) {
                --used[nums[start]];
                if (used[nums[start]] == 0) used.erase(nums[start]);
                ++start;
            }
            ans += end-start;           
        }
        return ans;
    }
};