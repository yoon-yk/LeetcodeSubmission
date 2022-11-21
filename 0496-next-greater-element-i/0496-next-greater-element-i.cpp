class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> dict;

        stack<int> st;
        for (int i=0; i<n; i++) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                dict[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        
        vector<int> ret;
        for (int& i : nums1) {
            if (!dict.count(i)) ret.push_back(-1);
            else ret.push_back(dict[i]);
        }
        
        return ret;
    }
};