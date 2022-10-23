class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0, xor0 = 0, xor1 = 0;
        for (int n: nums)
            xorr ^= n;
        for (int i = 1; i <= n; i++)
            xorr ^= i;
        int rightmostbit = xorr & ~(xorr - 1);
        for (int n: nums) {
            if ((n & rightmostbit) != 0)
                xor1 ^= n;
            else
                xor0 ^= n;
        }
        for (int i = 1; i <= n; i++) {
            if ((i & rightmostbit) != 0)
                xor1 ^= i;
            else
                xor0 ^= i;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == xor0)
                return {xor0, xor1};
        }
        return {xor1, xor0};
    }
};