class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> v(n);
        for (int i=0; i<n; ++i) {
            v[i].resize(i+1);
            for (int j=0; j<=i; ++j) {
                if (i == 0 || j == 0 || j == i) {
                    v[i][j] = 1;
                } else {
                    v[i][j] = v[i-1][j-1] + v[i-1][j];
                } 
            }
        }
        return v;
    }
};