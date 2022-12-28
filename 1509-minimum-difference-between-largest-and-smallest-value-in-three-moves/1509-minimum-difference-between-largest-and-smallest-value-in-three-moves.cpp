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
        int n = nums.size(), ans = INT_MAX;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<4; ++i) 
            ans = min(ans, abs(nums[i]-nums[n-1-(3-i)]));
        
        return ans;

    }
};