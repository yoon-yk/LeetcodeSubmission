class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // val : last idx;
        queue<pair<int, int>> Q; // val : idx;
        
        for (int i=0; i<nums.size(); ++i) {
            if (!Q.empty() && i-Q.front().second > k) {
                
                mp.erase(Q.front().first);
                Q.pop();
            }
            
            if (mp.count(nums[i])) return true;
            mp[nums[i]] = i;
            Q.push({nums[i], i});
        }
        return false;
    }
};