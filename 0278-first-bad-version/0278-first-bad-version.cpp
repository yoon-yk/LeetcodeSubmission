// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    /*
    
    false false true true true true
    
    */
    
    int firstBadVersion(int n) {
        int start = 0, end = n;
        while (start <= end){
            int mid = start + ((end-start) >> 1);
            if ((isBadVersion(mid) && !isBadVersion(mid-1)))
                return mid;
            if (isBadVersion(mid))
                end = mid-1;
            else start = mid + 1;
        }
        return -1;
    }
};