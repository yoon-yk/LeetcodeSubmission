class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int start = 0, end = nums.size()-1;
        int val, idx = nums.size()-1;
        while (start<=end){
            if (abs(nums[start]) < abs(nums[end])) {
                val = nums[end] * nums[end];
                end--;
            } else {
                val = nums[start] * nums[start];
                start++;
            }
            res[idx--] = val;
        }
        return res;
    }
};