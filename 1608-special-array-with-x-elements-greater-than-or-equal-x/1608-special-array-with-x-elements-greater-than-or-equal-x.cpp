class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();        
        /*
        0 0 3 4 4
        */
        for (int i=0; i<n; ++i)
            if ((i==0 || nums[i-1] < n-i) && (n-i <= nums[i])) return n-i;
        return -1;
    }
};