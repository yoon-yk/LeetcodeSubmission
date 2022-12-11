class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i=1; i<=n; i++) sum ^= i;
        for (int i=0; i<n; i++) sum ^= nums[i];

        return sum;
    }
};