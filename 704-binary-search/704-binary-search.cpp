class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start < end) {
            int mid = (start + end + 1) >> 1;
            if (nums[mid] == target) return mid;
            if (target < nums[mid] ) end = mid - 1;
            else start = mid;
        }
        return (nums[start]==target)? start : -1;
    }
};