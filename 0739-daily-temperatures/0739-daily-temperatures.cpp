class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0), incSt;
        for (int i=0; i<n; ++i) {
            auto & temp = t[i];
            while (!incSt.empty() && t[incSt.back()] < temp) {
                ans[incSt.back()] = i-incSt.back();
                incSt.pop_back();
            }
            incSt.push_back(i);
        }
        return ans;
    }
};