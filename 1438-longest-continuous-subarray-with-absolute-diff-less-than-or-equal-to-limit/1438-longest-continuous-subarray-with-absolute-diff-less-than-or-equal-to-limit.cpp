class Solution {
public:
    int longestSubarray(vector<int>& A, int limit) {
        deque<int> maxd, mind;
        int start = 0, end, ans = 0;
        for (end = 0; end < A.size(); ++end) {
            while (!maxd.empty() && A[end] > A[maxd.back()]) maxd.pop_back();
            while (!mind.empty() && A[end] < A[mind.back()]) mind.pop_back();
            maxd.push_back(end);
            mind.push_back(end);
            while (A[maxd.front()] - A[mind.front()] > limit) {
                if (maxd.front() == start) maxd.pop_front();
                if (mind.front() == start) mind.pop_front();
                ++start;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};