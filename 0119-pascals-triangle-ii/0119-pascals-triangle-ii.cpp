class Solution {
public:
/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
    vector<int> getRow(int rowIndex) {
        vector<int> prev(1, 1), cur;
        for (int i=0; i<34; ++i) {
            cur = vector<int>(rowIndex+1, 1);
            for (int j=1; j<i; ++j) {
                cur[j] = prev[j] + prev[j-1];
            }
            if (i == rowIndex) return cur;
            prev = cur;
        }
        return cur;
    }
};