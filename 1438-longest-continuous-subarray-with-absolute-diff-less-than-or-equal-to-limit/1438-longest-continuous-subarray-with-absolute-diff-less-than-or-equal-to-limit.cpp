class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        int i = 0, j, ans = 0;
        multiset<int> m;
        for (j = 0; j < A.size(); ++j) {
            m.insert(A[j]);
            while (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(A[i++]));
            ans = max(ans, (int)m.size());
        }
        return ans;
    }
};