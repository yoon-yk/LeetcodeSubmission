class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        set<int> v;
        for (int & n : nums) {
            auto it = v.lower_bound(n);
            if (it != v.end()) v.erase(it);
            v.insert(n);
            if (v.size() == 3) return true;
        }
        return false;
    }
};