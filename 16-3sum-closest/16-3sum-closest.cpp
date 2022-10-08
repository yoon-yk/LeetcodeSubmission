class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 100000, minDiff = 100000;
        for (int a = 0; a < n-2; a++) {
            twoSum(nums, a, target-nums[a], ans, minDiff);
        }
        return ans;
    }
    
    void twoSum(vector<int>& nums, int idx, int targetSum, int& ans, int& minDiff) {
        int begin = idx+1, end = nums.size()-1;
        int curSum;
        
        while (begin < end) {
            curSum = nums[begin] + nums[end];
            if (ans > 10000 || 
                abs(targetSum-curSum) < minDiff) {
                ans = curSum + nums[idx];
                minDiff = abs(targetSum-curSum);
            }
            if (nums[begin] + nums[end] < targetSum) {
                begin ++;
            } else {
                end --;
            }
        }
    }
};