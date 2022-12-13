class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v = nums1;
        for (auto &i : nums2) v.push_back(i);
       
        int totalLen = nums1.size() + nums2.size();
        int targetIdx = totalLen >> 1;
        if (totalLen % 2) { // odd
            quicksort(v, 0, totalLen-1, targetIdx);
            return v[targetIdx];
        }
        quicksort(v, 0, totalLen-1, targetIdx-1);
        int t1 = v[targetIdx-1];
        quicksort(v, 0, totalLen-1, targetIdx);
        int t2 = v[targetIdx];
        return (t1 + t2) * 0.5;
        
    }
    
    void quicksort(vector<int>&v, int start, int end, int targetIdx) {
        if (start == end) return;
        
        int ptIdx = partition(v, start, end);
        if (ptIdx == targetIdx) return;
        if (ptIdx < targetIdx) quicksort(v, ptIdx+1, end, targetIdx);
        else quicksort(v, start, ptIdx-1, targetIdx);
    }
    
    int partition (vector<int>& v, int start, int end) {
        
        int mid = start + ((end-start) >> 1);
        swap(v[mid], v[end]);
        
        int lo = start;
        for (int i=start; i< end; i++) {
            if (v[i] < v[end]) {
                swap(v[i], v[lo]);
                lo++;
            }
        }
        swap(v[lo], v[end]);
        
        return lo;
    }
    
};