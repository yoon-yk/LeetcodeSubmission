class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> left(n, -1), right(n, n), st;

        /*
                       *
            [ 1, 4, 3, 7, 4, 5]
        left[ X, 0, 0, 2, 2, 4]
        righ[ X, 2, X, 4, X, X]
        mulp[ 5, 4,15, 7,12, 5]
        
        */
        for (int i=n-1; i>=0; --i) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                // idx of the smaller & 
                // closest in the left-hand side elm 
                left[st.back()] = i; 
                st.pop_back();
            }
            st.push_back(i);
        }

        // clear
        st = vector<int>();

        for (int i=0; i<n; ++i) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                // idx of the smaller &
                // closest in the right-hand side elm
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (left[i] >= k || right[i] <= k) continue;
            ans = max(ans, nums[i] * ((right[i]-1)-(left[i]+1)+1));
        }
        return ans;
    }
};