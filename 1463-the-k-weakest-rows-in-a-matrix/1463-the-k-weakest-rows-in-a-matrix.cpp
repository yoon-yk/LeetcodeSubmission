class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> v;
        for (int i=0; i<mat.size(); ++i) {
            int sum = 0;
            for (int j=0; j<mat[0].size(); ++j) {
                sum += mat[i][j];
            }
            v.push_back({sum, i});
        }

        sort(v.begin(), v.end());

        vector<int> ans;
        for (int i=0; i<k; ++i) {
            ans.push_back(v[i][1]);
        }

        return ans;
    }
};