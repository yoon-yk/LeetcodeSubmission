// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1, end = n;
        int mid = first + (end-first)/2;
        
        while (first < end) {
            mid = first + (end-first)/2;            
            if (isBadVersion(mid)) end = mid;
            else first = mid + 1;
        }
        
        return first;
    }
};