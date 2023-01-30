class Solution {
public:
    vector<int> ps;

    Solution(vector<int>& w) {
        int sum = 0;
        for (auto & ww : w) {
            sum += ww;
            ps.push_back(sum);
        }
    }
    
    int pickIndex() {
        int maxN = ps.back();
        // [1 : max]
        int randValue = (rand() % (maxN)) + 1;
        auto it = lower_bound(ps.begin(), ps.end(), randValue);
        return it - ps.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */