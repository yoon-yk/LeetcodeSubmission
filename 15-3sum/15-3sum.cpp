class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        unordered_map <int, int> m;
        for (int n : nums)
            m[n]++;
        
        for (auto n:m) {
            int target = n.first;
            m[target]--;
            
            for (auto l:m) {
                if (l.first > target) continue;
                int left = l.first;
                if (m[left] == 0) continue;
                m[left]--;
                int right = -1 * (target+left);
                if (right <= left){
                    if (m.count(right) && m[right] > 0) {
                        ans.push_back({target, left, right});
                    }
                }
                m[left]++;
            }
            m[target]++;
        }
        
        return ans;
    }
};