class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0, right = h.size() - 1;
        int ans = 0;
        int lMax = 0, rMax = 0;
        while (left < right) {
            if (h[left] < h[right]) {
                if (h[left] >= lMax) {
                    lMax = h[left];
                } else {
                    ans += (lMax - h[left]);
                }
                ++left;
            } else {
                if (h[right] >= rMax) {
                    rMax = h[right];
                } else {
                    ans += (rMax - h[right]);
                }
                --right;
            }
        }
        return ans;
    }
};