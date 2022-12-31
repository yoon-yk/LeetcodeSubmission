class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == arr.size()) return arr;
        auto lo = lower_bound(arr.begin(), arr.end(), x);
        auto hi = upper_bound(arr.begin(), arr.end(), x);
        int lb = lo - arr.begin(), hb = hi - arr.begin();
        if (hb-lb > k) return vector<int> (k, x);
        
        int left, right;        
        while (hb-lb-1 < k) {
            if (lb < 0) ++hb;
            else if (hb >= arr.size()) --lb;
            else {
                left = x-arr[lb];
                right = arr[hb]-x;
                if (left == right) (arr[lb] < arr[hb]) ? --lb : ++hb;
                else (left < right) ? --lb : ++hb;    
            }
        }

        lb = max(0, lb+1);
        hb = min(hb, (int)arr.size());
        return vector<int> (arr.begin()+lb, arr.begin()+hb);
    }
};