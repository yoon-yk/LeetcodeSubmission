class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int result = 0;
        for (int i = 0; i < A.size() + B.size() - 1; ++i) {
            // The current overlapping window is A[aStart, Math.min(A.length, B.length)] and B[bStart, Math.min(A.length, B.length)].
            int aStart = max(0, (int)(A.size() - 1 - i));  
            int bStart = max(0, (int)(i - (A.size() - 1)));
            int numConsecutiveMatches = 0;
            for (int aIdx = aStart, bIdx = bStart; aIdx < A.size() && bIdx < B.size(); ++aIdx, ++bIdx) {
                // Maintain number of equal consecutive elements in the current window (overlap) and the max number ever computed.
                numConsecutiveMatches = A[aIdx] == B[bIdx] ? numConsecutiveMatches + 1 : 0;
                result = max(result, numConsecutiveMatches);
            }
        }
        return result;
    }
};

