class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> dict2;
        for (int i=0; i<n; i++)
            dict2[nums2[i]] = i;
        
        stack<int> st;
        for (int i=0; i<n; i++) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                ans[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> ret;
        for (int i : nums1) {
            if (ans[dict2[i]] > -1)
                ret.push_back(ans[dict2[i]]);
            else ret.push_back(-1);
        }
        
        return ret;
    }
};