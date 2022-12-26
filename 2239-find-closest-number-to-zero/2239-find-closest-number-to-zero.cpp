class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int& a, int& b) {
            int absA = abs(a), absB = abs(b);
            if (absA == absB) return a > b;
            return abs(a) < abs(b);
        });
        return nums[0];
    }
};