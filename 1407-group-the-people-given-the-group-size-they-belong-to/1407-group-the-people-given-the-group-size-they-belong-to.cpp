class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;

        for (int i=0; i<groupSizes.size(); ++i) {
            int targetSize = groupSizes[i];
            if (targetSize > 1 && mp[targetSize].empty())
                mp[targetSize].push_back(i);
            else {
                mp[targetSize].push_back(i);
                if (mp[targetSize].size() == targetSize) {
                    ans.push_back(mp[targetSize]);
                    mp[targetSize].clear();
                }
            }
        }

        return ans;
    }
};