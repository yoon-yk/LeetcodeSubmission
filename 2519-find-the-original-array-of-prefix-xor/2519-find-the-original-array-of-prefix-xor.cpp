class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        /*
        5    2  0  3  1
        101 10  0 11  1
        
        */
        int n = pref.size();
        vector<int> ans(n);
        ans[0] = pref[0];
        for (int i=1; i<n; ++i) {
            ans[i] = pref[i] ^ pref[i-1];
        }
        return ans;
    }
};