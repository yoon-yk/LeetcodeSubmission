class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        /*
        [73,74,75,71,69,72,76,73]
        [ 1, 1, 4, 2, 1, 1, 0, 0]
        */
        
        int n = temp.size();
        vector<int> arr(n, 0);
        stack<pair<int, int>> st;
        st.push({temp[0], 0});
        for (int i=1; i<n; i++) {
            while (!st.empty() && temp[i] > st.top().first) {
                int idx = st.top().second;
                arr[idx] = i-idx;
                st.pop();
            }
            st.push({temp[i], i});
        }
        return arr;
        
    }
};