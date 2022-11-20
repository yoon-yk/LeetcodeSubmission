class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        /*
        [73,74,75,71,69,72,76,73]
        [ 1, 1, 4, 2, 1, 1, 0, 0]
        
        */
        
        int dist, tp, n = temp.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for (int i=0; i<n; i++) {
            tp = temp[i];
            while (!st.empty() && temp[st.top()] < tp) {
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};