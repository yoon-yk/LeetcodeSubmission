class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        unordered_map<int, int> leftSums;
        leftSums[0] = -1;

        int ans = INT_MAX, leftSum = 0;
        for (int i=0; i<nums.size(); ++i) {
            leftSum += nums[i];
            if (x == leftSum && ans == INT_MAX) ans = i+1;
            if (leftSums.count(leftSum)) continue;
            leftSums[leftSum] = i;
        }

        int rightSum = 0;
        for (int i=nums.size()-1; i>=0; --i) {
            rightSum += nums[i];
            int target = x-rightSum;
            if (leftSums.count(target)) {
                if (leftSums[target] >= i) continue;
                ans = min(ans, (int)nums.size()-i + leftSums[target] + 1);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};