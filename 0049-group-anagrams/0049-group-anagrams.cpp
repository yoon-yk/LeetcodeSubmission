class Solution {
public:
    string cntToString(string& str) {
        vector<int> cnt(26, 0);
        for (auto& ch : str)
            cnt[ch-'a']++;
        
        string modified_str;
        for (int i=0; i<26; i++) {
            modified_str += to_string(cnt[i]);
            modified_str += '/';
        }
        return modified_str;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<int>> mp;
        for (int i=0; i<n; i++) {
            mp[cntToString(strs[i])].push_back(i);
        }
        
        vector<vector<string>> ans;
        for (auto& [_, idxes]: mp) {
            ans.push_back({});
            for (auto & idx : idxes) 
                ans.back().push_back(strs[idx]);
        }
        
        return ans;
    }
};