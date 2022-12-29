class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int target = 1;
        while (s.count(target++));
        return target-1;
    }
};