class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if (hand.size() % k ) return false;
        
        map<int, int> hashM;
        for (auto & i : hand) ++hashM[i];

        for (auto & [val, freq] : hashM) {
            if (freq == 0) continue;
            int curV = val, cnt = 1;
            while (cnt < k) {
                if ((hashM[++curV] -= freq) < 0)
                    return false;
                cnt++;
            }            
        }
        return true;
    }
};