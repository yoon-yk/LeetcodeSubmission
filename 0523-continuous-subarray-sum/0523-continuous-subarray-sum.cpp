class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        int ps = 0, prev = 0;
        for (int i=0; i<nums.size(); ++i) {
            ps = (ps + nums[i]) % k;
            if ((ps == 0 && i > 0) || st.count(ps)) return true;
            st.insert(prev);
            prev = ps;
        }
        return false;
    }
};