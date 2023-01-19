class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto hi = lower_bound(arr.begin(), arr.end(), x); // equal or bigger thaan x
        
        auto lo = upper_bound(arr.begin(), arr.end(), x);
        if (lo != arr.begin()) --lo;
                
        while (hi-arr.begin() - (lo-arr.begin()) <= k) {
            if (lo != prev(arr.begin()) && hi != arr.end()) {
                if (abs((*lo)-x) > abs((*hi)-x)) ++hi;
                else --lo;
            } else if (lo != prev(arr.begin())) {
                -- lo;
            } else {
                ++ hi;
            }
        }
        
        
        return vector<int>(lo+1, hi);
    }
};