class Solution {
public:
    int totalTime(vector<int>& piles, int bananaN) {
        int cnt = 0;
        for (int i=0; i<piles.size(); i++) {
            // cnt += ceil((double)piles[i] / (double)bananaN);
            cnt += (piles[i]/bananaN) + (piles[i]%bananaN>0);
        }
        return cnt;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
    
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        int mid;

        while (lo < hi) {
            mid = (lo + ((hi-lo) >> 1));

            if (totalTime(piles, mid) <= h) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        
        return lo;
    }
};