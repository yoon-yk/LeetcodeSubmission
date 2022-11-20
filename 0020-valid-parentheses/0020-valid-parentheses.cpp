class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto & ch : s) {
            if (ch == '[' || ch == '(' || ch == '{')
                st.push(ch);
            else {
                if (ch == ']') {
                    if (!st.empty() && st.top() == '[')
                        st.pop();
                    else return false;
                } else if (ch == '}') {
                    if (!st.empty() && st.top() == '{')
                        st.pop();
                    else return false;
                } else if (ch == ')') {
                    if (!st.empty() && st.top() == '(')
                        st.pop();
                    else return false;
                }
            }
        }
        return (st.empty());
    }
};