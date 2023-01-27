class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
        S1 + S2 = SUM
        DIFF = S2 - S1 (S2 >= S1)
             = (SUM-S1) - S1
             = SUM - 2*S1
             // S1을 최대한으로 만들기 (sum/2 >= S1)
        */
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum>>1;
        vector<int> prev(target + 1, 0), cur(target + 1, 0);
        prev[0] = 1, cur[0] = 1;
        for (int i=0; i<stones.size(); ++i) {
            for (int s=target; s>=0; --s) {
                if (s-stones[i] >= 0) {
                    cur[s] += prev[s-stones[i]];
                } 
                
                if (i==stones.size()-1) {
                    if (cur[s] > 0) return (sum-s*2);
                }            
            }
            prev = cur;
        }

        return -1;
    }
};