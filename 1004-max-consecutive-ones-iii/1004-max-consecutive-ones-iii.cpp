class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zcnt = 0, l=0, r;
        for (r=0; r<nums.size(); ++r) {
            zcnt += !nums[r];
            
            if (zcnt > k) {
                zcnt -= !nums[l];
                ++l;
            }
        }
        return (r-l);
    }
};