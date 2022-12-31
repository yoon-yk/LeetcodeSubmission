class Solution {
public:
    bool makesquare(vector<int>& ms) {
        int sum = accumulate(ms.begin(), ms.end(), 0);
        if (sum % 4 != 0) return false;
        sort(ms.begin(), ms.end(), greater<>());
        vector<int> curW(4, sum >> 2);
        return backtrack(0, ms, curW, 4);
    }
    
    bool backtrack(int i, vector<int>& ms, vector<int>& curW, int comp) {

        if (i == ms.size())
            return (comp == 0);
        
        bool ret = false;
        for (int d=0; d<4; ++d) {
            if (curW[d] < ms[i]) continue;
            curW[d] -= ms[i];
            if (curW[d] == 0) {
                if (backtrack(i+1, ms, curW, comp-1)) return true;
            } else {
                if (backtrack(i+1, ms, curW, comp)) return true;
            }
            curW[d] += ms[i];
        }
        return ret;
    }
};