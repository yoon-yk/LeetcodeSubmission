class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        unordered_map<int, int> leftSums;
        leftSums[0] = -1;

        int ans = INT_MAX, leftSum = 0;
        for (int i=0; i<nums.size(); ++i) {
            leftSum += nums[i];
            if (x == leftSum) ans = min(ans, i+1);
            if (leftSums.count(leftSum)) continue;
            leftSums[leftSum] = i;
        }

        // for (auto & [n, id] : leftSums) {
        //     cout << n << '_' << id << endl;
        // }

        int rightSum = 0;
        for (int i=nums.size()-1; i>=0; --i) {
            rightSum += nums[i];
            // cout << rightSum << endl;
            if (leftSums.count(x-rightSum)) {
                if (leftSums[x-rightSum] >= i) continue;
                // cout << "found " << x-rightSum << " at " << leftSums[x-rightSum] << endl;
                ans = min(ans, (int)nums.size()-i + leftSums[x-rightSum] +  1);
                // cout << "ans updated to " << ans << "(" << nums.size()-i << "+" << leftSums[x-rightSum]<< " + " << 1 << ")" << endl; 
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};