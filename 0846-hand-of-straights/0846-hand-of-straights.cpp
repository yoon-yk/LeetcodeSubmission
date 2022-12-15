class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        
        /*
        1 2 3 6 2 3 4 7 8
        
        1 2 3 4 6 7 8 9 2 3 4 5 3 4 5 6, k = 4
        
        1 2 2 3 3 3 4 4 4 5 5 6 6 7 8 9, k = 4
        
        2 
        1 2 2 
        
        // max freq <= k
        // size % k == 0
        */
        
        map<int, int> hashM;
        for (auto & i : hand) ++hashM[i];
        
        for (auto & [val, freq] : hashM) {

            for (int f=0; f < freq; ++f) {
                int cur = val+1, cnt = 1;
                while (hashM[cur] > 0 && cnt < k) {
                    ++cnt, --hashM[cur];
                    ++cur;
                }
                if (cnt != k) return false;
            }
        }
        return true;
    }
};