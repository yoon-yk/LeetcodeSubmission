class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        /*
        a + b > c(max)
        */
        
        int sum = 0, maxN = INT_MIN;
        sort(nums.begin(), nums.end());
        
        /*
        [3,2,3,4]
        ==> [2, 3, 3, 4]
        */
        
        int curMax = nums.size()-1;
        while ( 1 < curMax ) {
            if (nums[curMax-2] + nums[curMax-1] > nums[curMax])
                return nums[curMax-2] + nums[curMax-1] + nums[curMax];
            curMax--;
        }
    
        return 0;
    }
};