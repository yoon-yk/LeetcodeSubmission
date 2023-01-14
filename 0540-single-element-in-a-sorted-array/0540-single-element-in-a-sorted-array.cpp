class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sum = 0;
        for (int & n : nums) sum ^= n;
        return sum;
    }
};