class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int, int> mp;
        
        int n = f.size(), ans = 0, start = 0, cnt = 0;
        for (int end=0; end<n; ++end) {
            ++mp[f[end]];
            if (mp[f[end]] == 1) ++cnt;
            
            if (cnt > 2) {
                --mp[f[start]];
                if (mp[f[start]] == 0) --cnt;
                ++start;
            }
            ans = max(end-start+1, ans);
        }
        return ans;
    }
};