class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int w = abs(sx-fx), h = abs(sy-fy);
        if (!w && !h && t == 1) return false;
        int minRequired = max(w, h);
        return minRequired <= t;
    }
};