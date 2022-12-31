class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == arr.size()) return arr;
        auto lo = lower_bound(arr.begin(), arr.end(), x);
        if (lo == arr.begin()) {
            vector<int> ans(arr.begin(), arr.begin() + k);
            return ans;
        } 
        auto hi = upper_bound(arr.begin(), arr.end(), x);
        int lb = lo - 1 - arr.begin() , hb = hi - arr.begin();
        if (hb-lb > k) {
            return vector<int> (k, x);
        }
        int left, right;
        cout << lb << " " << hb << "| k " << k << endl;
        
        while (hb-lb-1 < k) {
            if (lb < 0) ++hb;
            else if (hb >= arr.size()) --lb;
            else {
                left = x-arr[lb];
                right = arr[hb]-x;
                if (left == right) {
                    if (arr[lb] < arr[hb]) --lb;
                    else ++hb;
                } else if (left < right) --lb;
                else ++hb;                
            }
        }
        cout << "res : " <<  lb << " " << hb << endl;

        lb = max(0, lb+1);
        hb = min(hb, (int)arr.size());
        // cout << "res : " <<  lb << " " << hb << endl;
        return vector<int> (arr.begin()+lb, arr.begin()+hb);
    }
};