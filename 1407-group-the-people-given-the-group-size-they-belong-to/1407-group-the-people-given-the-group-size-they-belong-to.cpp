class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<vector<int>>> mp;
        for (int i=0; i<groupSizes.size(); ++i) {
            int targetSize = groupSizes[i];
            if (mp[targetSize].empty() || 
                mp[targetSize].back().size() == targetSize) 
                mp[targetSize].push_back({i});
            else {
                mp[targetSize].back().push_back(i);
            }
        }

        vector<vector<int>> ans;
        for (auto & [_, vs] : mp) {
            for (auto & v : vs) {
                ans.push_back(v);
            }
        }

        return ans;
    }
};