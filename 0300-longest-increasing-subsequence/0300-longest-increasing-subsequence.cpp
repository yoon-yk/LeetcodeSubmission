class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        /*
        
        2
        9  3   18
        10 5 7 101
        
        
        7
        5 
        2 3 9 10 
        */
        
        int ans = 0;
        int n = nums.size();
        vector<int> stTops;
        for (int i=0; i<n; ++i) {
            int idx = lower_bound(stTops.begin(), stTops.end(), nums[i]) - stTops.begin();
            if (idx == stTops.size()) stTops.push_back(nums[i]);
            else stTops[idx] = nums[i];
        }
        
        return stTops.size();
    }
};