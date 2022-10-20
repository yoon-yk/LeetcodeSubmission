/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int start = 0, end = 10000;
        while (start <= end) {
            int mid = start + ((end-start) >> 1);
            if (reader.get(mid) == target)
                return mid;
            if (reader.get(mid) < target)
                start = mid + 1;
            else end = mid-1;
        }
        return -1;
    }
};