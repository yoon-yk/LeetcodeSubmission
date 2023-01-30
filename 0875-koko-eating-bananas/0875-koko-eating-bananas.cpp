class Solution {
public:
    int hours(vector<int>& piles, int bananas) {
        int ans = 0;
        for (int & p : piles) {
            ans += (p/bananas) + (p % bananas != 0);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
        sum, ...., h, ..., ..., number of piles ...
        1개씩       k개씩         maximum element 
        
        sum >= h >= number of piles
        
        k를 구해야 하는데, h값을 갖게 하는 가장 작은 수
        */
        
        int lo = 1, hi = *max_element(piles.begin(), piles.end()), mi;
        
        while (lo < hi) {
            mi = lo + ((hi-lo) >> 1);
            if (hours(piles, mi) > h) {
                lo = mi+1;
            } else {
                hi = mi;
            }
        }
        
        return lo;
    }
};