class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        int left = 0;
        stack<char> st;
        for (auto &c : s) {
            if (c == '(') {
                ++left;
                st.push(c);
            } else if (c == ')') {
                if (left > 0) {
                    --left;
                    st.push(c);
                }
            } else {
                st.push(c);
            }
        }
        
        while (!st.empty()) {
            if (st.top() == '(' && left > 0) {
                --left;
            } else ans += st.top(); st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};