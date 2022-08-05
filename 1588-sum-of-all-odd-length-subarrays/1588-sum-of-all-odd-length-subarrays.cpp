class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0, size = arr.size();
        for (int i=0; i<size; i++) {
            ans += ((((size-i) * (i+1)) + 1) >> 1) * arr[i];
        }
        return ans;
    }
};