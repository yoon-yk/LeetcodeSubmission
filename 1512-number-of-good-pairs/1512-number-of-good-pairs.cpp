class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        /*
        1 1 1 2 3 3
        */
        int num, hi, ans = 0;
        for (int i=0; i<nums.size()-1; ++i) {
            num = nums[i];
            hi = upper_bound(nums.begin(), nums.end(), num) - nums.begin()-1;
            if (i+1 <= hi && nums[i+1] == num && nums[hi] == num) 
                ans += hi-(i+1)+1;

        }
        
        return ans;
    }
};