class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;
        int ps = 0, cur, prev = 0;
        for (int i=0; i<nums.size(); ++i) {
            ps += nums[i];
            cur = ps % k;
            if ((cur == 0 && i > 0) || st.count(cur)) return true;
            st.insert(prev);
            prev = cur;
        }
        return false;
    }
};