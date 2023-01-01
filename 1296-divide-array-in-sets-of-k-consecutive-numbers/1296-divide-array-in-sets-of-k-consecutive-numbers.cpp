class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int, int> mp;
        for (int & i : nums) ++mp[i];
        // for (auto [i,freq]:mp) cout << i << "/" << freq << endl;
        
        for (auto [val, freq] : mp) {
            if (freq == 0) continue;
            
            for (int i=0; i<k; ++i) {
                // cout << val << ":" << mp[val+i] << ":" << freq << endl;
                if (mp[val+i]-freq < 0) return false;
                mp[val+i] -= freq;
                // cout << mp[val+i] << endl;
            }
        }
        
        return true;
    }
};