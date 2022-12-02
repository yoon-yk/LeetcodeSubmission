class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int fastIdx = nums[0], slowIdx = nums[0];
        do {
            fastIdx = nums[nums[fastIdx]];
            slowIdx = nums[slowIdx];
        } while (fastIdx != slowIdx);
        
        slowIdx = nums[0];
        while (fastIdx != slowIdx) {
            fastIdx = nums[fastIdx];
            slowIdx = nums[slowIdx];
        }
        
        return fastIdx;
    }
};