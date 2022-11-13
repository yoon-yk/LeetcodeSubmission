class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> hashM;
        
        int idx = 0;
        for (auto & str : strs) {
            string dup = str;
            sort(dup.begin(), dup.end());
            hashM[dup].push_back(idx++);
        }
        
        idx = 0;
        vector<vector<string>> ans;
        for (auto &[_, vec] : hashM) {
            ans.push_back({});
            for (auto & i : vec) {
                // cout << strs[i] << endl;
                ans[idx].push_back(strs[i]);
            }
            idx++;
        }
        
        return ans;
    }
};