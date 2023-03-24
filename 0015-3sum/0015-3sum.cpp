class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      sort(nums.begin(), nums.end()); // O(N log N)
      // int hi = 
      vector<vector<int>> ans;
      for (int c=0; c<nums.size(); c++) { // c = 1

        if (c > 0 && nums[c] == nums[c-1]) continue;
        // target = -1 * -1 = 1
        int target = nums[c] * -1;

        twoSum(nums, c+1, nums.size()-1, target, ans); // lo : 2, hi = 5 

        // ans : [[2, 5, 0], ]
      } 
      return ans;
    }
    
    
    void twoSum(vector<int>& nums, int lo, int hi, int target, vector<vector<int>>& ans) { // O(len of array) = O(N)
      while (lo < hi) { 
        if (nums[lo] + nums[hi] == target) { 

          ans.push_back({nums[lo], nums[hi], -1 * target});

          int tmp = hi;
          while (0 <= tmp && nums[hi] == nums[tmp]) --tmp;
          hi = tmp;


        } else if (nums[lo] + nums[hi] < target) {
          ++lo;
        } else {
          --hi;
        }
      }
    }

};