class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 100000, minDiff = 100000;
        for (int a = 0; a < n-2; a++) 
            twoSum(nums, a, target, ans, minDiff);
        return ans;
    }
    
    void twoSum(vector<int>& nums, int idx, int target, int& ans, int& minDiff) {
        int begin = idx+1, end = nums.size()-1;
        int curSum;
        
        while (begin < end) {
            curSum = nums[begin] + nums[end] + nums[idx];
            if (abs(target-curSum) < minDiff) {
                ans = curSum;
                minDiff = abs(target-curSum);
            }
            if (curSum < target)
                begin ++;
            else
                end --;
        }
    }
};