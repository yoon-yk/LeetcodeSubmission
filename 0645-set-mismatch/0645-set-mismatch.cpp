class Solution {
public:
vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n);
        vector<int> ans = {0,0};
        for(int i = 0; i < n; i++) {
            if (++count[nums[i]-1] == 2)
                ans[0] = nums[i];
            ans[1] ^= (i+1) ^ nums[i];
        }
        ans[1] ^= ans[0];
        return ans;
    }
};