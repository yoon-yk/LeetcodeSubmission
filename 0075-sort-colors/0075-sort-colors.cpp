class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] == 0) swap(nums[i], nums[lo++]);
        for (int i=nums.size()-1; i>=lo; --i) 
            if (nums[i] == 2) swap(nums[i], nums[hi--]);
    }
};