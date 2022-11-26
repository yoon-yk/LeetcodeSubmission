class Solution {
public:
    int totalTime(vector<int>& piles, int bananaN) {
        int cnt = 0;
        for (int i=0; i<piles.size(); i++) {
            cnt += ceil((double)piles[i] / (double)bananaN);
        }
        return cnt;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
    
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        int mid;
        
        // cout << printf("%.10f", ((float)100000000 / (float)49999998)) << endl;
        // cout << printf("%.10f", ceil((double)100000000 / (double)49999998)) << endl;

        
        while (lo < hi) {
            mid = (lo + ((hi-lo) >> 1));
            // cout << lo << " " << mid << " " << hi << endl;

            if (totalTime(piles, mid) <= h) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
        
        return lo;
    }
};