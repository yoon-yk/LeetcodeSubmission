class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> v;
        for (int & n : nums) {
            auto it = lower_bound(v.begin(), v.end(), n);
            if (it != v.end()) *it = n;
            else v.push_back(n);
            if (v.size() == 3) return true;
        }
        return false;
    }
};