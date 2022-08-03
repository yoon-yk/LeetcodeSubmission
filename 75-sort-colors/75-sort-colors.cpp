class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (!nums.size()) return;
        
        int target = 0;
        int i, j;
        for (i=0; i<nums.size(); i++) {
            bool found = false;
            while (!found) {
                for (j=i; j<nums.size(); j++) {
                    if (nums[j] == target) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
                target++;
            }
            swap(nums[i], nums[j]);
        }
        
    }
};