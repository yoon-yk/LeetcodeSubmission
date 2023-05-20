class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int start = n, end = -1, curMaxIdx = 0;
        vector<int> st;
        for (int i=0; i<n; ++i) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                auto cur = st.back(); st.pop_back();
                start = min(start, cur);
            }

            if (nums[curMaxIdx] > nums[i]) {
                end = i;
            }
            if (nums[curMaxIdx] < nums[i]) {
                curMaxIdx = i;
            }
            st.push_back(i);
        }
        
        return end < 0 ? 0 : end-start+1;
    }
};