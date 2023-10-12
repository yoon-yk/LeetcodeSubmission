/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        // find the peak
        int lo = 1, hi = mountainArr.length()-1, peak = -1;
        int cur;

        while (lo <= hi) {
            int mi = lo + ((hi-lo)>>1);
            int prev = mountainArr.get(mi-1), 
            next = mountainArr.get(mi+1);

            cur = mountainArr.get(mi);

            if (prev < cur && cur > next) {
                peak = mi; 
                break;
            } else if (prev < cur) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        if (cur == target) return peak;
        
        // find in the lower side
        lo = 0, hi = peak-1;
        
        while (lo <= hi) {
            int mi = lo + ((hi-lo)>>1);
            cur = mountainArr.get(mi);
            if (cur == target) {
                return mi;
            } else if (cur < target) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        
        // find in the upper side
        lo = peak, hi = mountainArr.length()-1;
        while (lo <= hi) {
            int mi = lo + ((hi-lo)>>1);
            cur = mountainArr.get(mi);
            if (cur == target) {
                return mi;
            } else if (cur < target) {
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        }
        return -1;
    }
};