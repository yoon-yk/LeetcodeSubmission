class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+(k%len));
        reverse(nums.begin()+(k%len), nums.end());
    }
};