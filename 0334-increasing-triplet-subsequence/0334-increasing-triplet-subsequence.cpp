class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f = INT_MAX, s = INT_MAX;
        for (int & n : nums) {
            if (n <= f) {
                f = n;
            } else if (n <= s) {
                s = n;
            } else return true;    
        }
        return false;
    }
};