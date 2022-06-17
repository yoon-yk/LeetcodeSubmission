// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1, end = n;
        int mid = first + (end-first)/2;
        
        while (first <= end) {
            mid = first + (end-first)/2;
            printf("first : %d, end : %d, mid : %d\n", first, end, mid);
            
            if (isBadVersion(mid) && !isBadVersion(mid-1)) return mid;
            if (isBadVersion(mid)) end = mid - 1;
            else first = mid + 1;
        }
        
        return mid;
    }
};