class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        unordered_map<int, int> prev, now;
        prev[0] = 1;
        for (int i=0; i<nums.size(); ++i) {
            for (auto & [v, f] : prev) 
                now[v+nums[i]] += f, now[v-nums[i]] += f;
            prev = now;
            now.clear();
        }
        return prev[target];
    }
};