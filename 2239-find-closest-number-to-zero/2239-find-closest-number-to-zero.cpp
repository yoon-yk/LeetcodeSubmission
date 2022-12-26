class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        return *min_element(nums.begin(), nums.end(), [&](int& a, int& b) {
            int absA = abs(a), absB = abs(b);
            return (absA == absB) ?  a > b : abs(a) < abs(b);
        });
    }
};