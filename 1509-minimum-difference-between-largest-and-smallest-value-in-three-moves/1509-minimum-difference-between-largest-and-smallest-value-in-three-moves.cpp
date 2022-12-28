class Solution {
public:
    int minDifference(vector<int>& nums) {
        /* min/max인 애들 3개 빼고 n-2개일 때 최소 
        
        2, 3, 4, 5
        
        0, 1, 5, 10, 14
        
        0, 50, 51, 51, 100
                ^          
        */
        
        if (nums.size() < 5) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int a = abs(nums[0]-nums[n-4]);
        int b = abs(nums[1]-nums[n-3]);
        int c = abs(nums[2]-nums[n-2]);
        int d = abs(nums[3]-nums[n-1]);
        
        return min(min(a, b), min(c, d));

    }
};