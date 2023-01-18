class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size(), ans = 0, minV = arr[0];
        /*
        a<b, arr[b] - arr[a]
        */
        for (int i=1; i<n; ++i) {
            ans = max(arr[i]-minV, ans); 
            minV = min(minV, arr[i]);
        }
        return ans;
    }
};