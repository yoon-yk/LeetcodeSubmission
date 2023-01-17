class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        /*
        3, 1, 2, 2, 2, 1, 3
        
        
        (i * j) % k = 0
        ((i%k) * (j%k)) % k = 0
        */
        
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        for (int i=0; i<nums.size(); ++i) {
            int cur = nums[i];
            if (i%k == 0) {
                ans += mp[cur].size();
            } else {
                for (auto & v : mp[cur]) {
                    if ((i*v)%k == 0) {
                        ++ans;
                    }
                }
            }
            mp[cur].push_back(i);
        }
        return ans;
    }
};