class Solution {
public:
    int shortestWay(string src, string tgt) {
        int s = 0, t = 0, ans = 1, cycle = false;
        while (t < tgt.size()) {
            cycle = false;
            if (s == src.size()) {++ans; s=0;}
            while (src[s] != tgt[t]) {
                ++s;
                if (s == src.size()) {
                    if (cycle) return -1;
                    cycle = true;
                    ++ans; s = 0;
                }
            }
            ++s, ++t;
        }
        return ans;
    }
};