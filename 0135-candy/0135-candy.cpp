class Solution {
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();
        vector<int> ret(n, 1);

        for (int i=0; i<n-1; ++i) {
            if (ratings[i] < ratings[i+1]) {
                ret[i+1] = ret[i]+1;
            }
        }

        for (int i=n-1; i>=1; --i) {
            if (ratings[i-1] > ratings[i]) {
                if (ret[i-1] > ret[i]) continue;
                ret[i-1] = ret[i]+1;
            }
        }

        return accumulate(ret.begin(), ret.end(), 0);
    }
};