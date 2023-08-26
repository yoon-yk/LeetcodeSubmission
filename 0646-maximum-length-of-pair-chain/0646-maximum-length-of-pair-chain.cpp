class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b){
          if (a[1] == b[1]) return a[0] < b[0];
          return a[1] < b[1];
        });

        int end = INT_MIN, cnt = 0;
        for (int i=0; i<pairs.size(); ++i) {
          if (end >= pairs[i][0]) continue;
          end = pairs[i][1];
          ++cnt;
        }

        return cnt;
    }
};