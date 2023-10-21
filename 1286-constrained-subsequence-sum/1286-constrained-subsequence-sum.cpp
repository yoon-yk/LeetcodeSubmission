class Solution {
public:
    using pii = pair<int, int>;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pii> pq; // max sum
        pq.push({nums[0], 0}); // cursum, index
        int ans = nums[0]; // to prevent the empty 

        for (int i=1; i<nums.size(); ++i) {
            while (i-pq.top().second > k) pq.pop(); // remove OOBs

            // possible maximum ==> add or not
            int cur = max(0, pq.top().first) + nums[i];
            pq.push({cur, i}); 

            ans = max(ans, cur);
        }
        return ans;
    }
};