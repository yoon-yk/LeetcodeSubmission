class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        unordered_set<string> seen;
        vector<vector<int>> ans;

        for (int i = 0; i < p; i++) {
            string curBit;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    subs[i].push_back(nums[j]);
                    curBit += (nums[j]+'0');
                    curBit += ',';
                }
            }
            // cout << curBit << endl;
            if (!seen.count(curBit)) {
                seen.insert(curBit);
                ans.push_back(subs[i]);
            }
        }
        

        
        return ans;
    }
};