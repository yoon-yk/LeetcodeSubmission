class Solution {
public:
    bool isNStraightHand(vector<int> hand, int W) {
        map<int, int> c;
        for (int i : hand) c[i]++;
        queue<int> start;
        int last_checked = -1, opened = 0;
        for (auto & [val, freq] : c) {
            if (opened > 0 && val > last_checked + 1 ||
                opened > c[val]) return false;

            start.push(freq - opened);
            last_checked = val, opened = freq;
            if (start.size() == W) {
                opened -= start.front();
                start.pop();
            }
        }
        return opened == 0;
    }
};