class Solution {
public:
    typedef long long ll;
    
    int mySqrt(int x) {
        ll start = 0, end = x, mid;
        while (start < end) {
            mid = (start+end+1) >> 1;
            if (x < mid*mid) 
                end = mid-1;
            else start = mid;
        }
        
        return start;
    }
};