class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*
         nums = [-1,2,1,-4], target = 1
         
         a + b  = target - c
         -1  1  = 1 
         
         a + b - target = -c
         
         a + b + c ~ target
         
          [-4,-1,1,2]
            |      |
        
        */
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        /*
        a + b + c = target
        b + c ~ target - a
        -4 - 5 = -9
        -1 - 5 = -6
         1 - 5 = -4
         2 - 5 = -3
        */
        
        int ans = 100000, minDiff = 100000;
        for (int a = 0; a < n; a++) {
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