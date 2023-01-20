class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0, b=nums.size()-1;   
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[r], nums[i]);
                ++r;
            }
        }
        
        for (int i=r; i<=b; ) {
            if (nums[i] == 2) {
                swap(nums[b], nums[i]);
                --b;
            } else ++i;
        }
    }
};