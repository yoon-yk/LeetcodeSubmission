class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> numSeq;
        for (int i=0; i<n; i++) {
            int idx = lower_bound(numSeq.begin(), numSeq.end(), nums[i]) - numSeq.begin();
            if (numSeq.empty() || idx >= numSeq.size()) {
                numSeq.push_back(nums[i]);
            } else {
                numSeq[idx] = nums[i];
            }
            if (numSeq.size() == 3) return true;
        }
        return false;
    }
};