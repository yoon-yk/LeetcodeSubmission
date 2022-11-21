class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        int start = 0, end, ans = 0;
        multiset<int> m;
        for (end = 0; end < A.size(); ++end) {
            m.insert(A[end]);
            while (*m.rbegin() - *m.begin() > limit)
                m.erase(m.find(A[start++]));
            ans = max(ans, (int)m.size());
        }
        return ans;
    }
};