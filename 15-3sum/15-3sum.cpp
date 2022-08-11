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
                int left = l.first;
                int right = -1 * (target+left);
                if (left > target || m[left] == 0 || right > left) continue; 
                m[left]--;
                if (m.count(right) && m[right] > 0)
                    ans.push_back({target, left, right});
                m[left]++;
            }
            m[target]++;
        }
        
        return ans;
    }
};