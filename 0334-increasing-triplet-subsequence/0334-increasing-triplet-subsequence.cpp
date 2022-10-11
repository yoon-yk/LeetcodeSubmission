class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> numSeq;
        int firstSmallest = INT_MAX, secondSmallest = INT_MAX;
        for (int i=0; i<n; i++) {
            if (firstSmallest == INT_MAX || nums[i] <= nums[firstSmallest]) {
                firstSmallest = i;
            } else if (secondSmallest == INT_MAX || nums[i] <= nums[secondSmallest]) {
                secondSmallest = i;
            } else {
                return true;
            }
        }
        return false;
    }
};