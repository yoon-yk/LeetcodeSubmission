class Solution {
public:
    int shortestWay(string src, string tgt) {
        int s = 0, t = 0, ans = 1, cycle = false;
        while (t < tgt.size()) {
            cycle = false;
            if (s == src.size()) {++ans; s%=src.size();}
            while (src[s] != tgt[t]) {
                ++s;
                if (s == src.size()) {
                    if (cycle) return -1;
                    cycle = true;
                    ++ans; s%=src.size();
                }
            }
            ++s, ++t;
        }
        return ans;
    }
};