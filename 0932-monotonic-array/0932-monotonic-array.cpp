class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        // increasing
        for (int i=1; i<n; ++i) {
            if (nums[i-1] > nums[i]) {
                flag = false;
                break;
            }
        }
        if (flag) return true;

        // decreasing
        flag = true;
        for (int i=1; i<n; ++i) {
            if (nums[i-1] < nums[i]) {
                flag = false;
                break;
            }
        }

        return flag;
    }
};