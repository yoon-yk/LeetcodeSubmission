class Solution {
public:
    int partition (vector<int>& arr, int start, int end){
        swap(arr[start+rand()%(end-start+1)], arr[end]);
        int lo = start;
        for (int i=start; i<end; ++i) {
            if (mp[arr[i]] < mp[arr[end]] || (mp[arr[i]] == mp[arr[end]]) && arr[i] < arr[end])
                swap(arr[i], arr[lo++]);
        }
        swap(arr[lo], arr[end]);
        return lo;
    }
    
    void quicksort(vector<int>& arr, int start, int end, int k) {
        if (start >= end) return;
        int idx = partition(arr, start, end);
        if (idx == k) return;
        if (idx < k) quicksort(arr, idx+1, end, k);
        else quicksort(arr, start, idx-1, k);
    }
    
    unordered_map<int, int> mp;
    int getKth(int lo, int hi, int k) {
        mp[1] = 0;
        vector<int> arr(hi-lo+1);
        iota(begin(arr), end(arr), lo);
        for (int i=lo; i<=hi; ++i) 
            getPowerValue(i);
        
        quicksort(arr, 0, hi-lo, k-1);
        
        return arr[k-1];
    }
    
    int getPowerValue(int i) {
        if (mp.count(i)) return mp[i];
        if (i&1) 
            mp[i] = getPowerValue(i*3 + 1) + 1;
        else 
            mp[i] = getPowerValue(i >> 1) + 1;
        return mp[i];
    }
};