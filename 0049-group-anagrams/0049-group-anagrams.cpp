class Solution {
public:
    void hashString(int idx, vector<string>& strs, unordered_map<string, vector<int>>& mp) {
        vector<int> cnt(26, 0);
        for (auto& ch : strs[idx])
            cnt[ch-'a']++;
        
        string modified_str;
        for (int i=0; i<26; i++) {
            modified_str += to_string(cnt[i]);
            modified_str += ' ';
        }
        mp[modified_str].push_back(idx);
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<int>> mp;
        for (int i=0; i<n; i++) {
            hashString(i, strs, mp);
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