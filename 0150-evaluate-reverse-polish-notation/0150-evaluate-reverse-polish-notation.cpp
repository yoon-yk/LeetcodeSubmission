class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        unordered_set<string> set = {"+", "-", "*", "/"};
        for (auto& tk : tokens) {
            if (set.count(tk)){
                long second = st.top(); st.pop();
                long first = st.top(); st.pop();
                if (tk == "+") {
                    st.push(first+second);
                } else if (tk == "-") {
                    st.push(first-second);
                } else if (tk == "*") {
                    st.push(first*second);
                } else if (tk == "/") {
                    st.push(first/second);
                }
            } else {
                st.push(stoi(tk));
            }
        }
        int ans = st.top(); st.pop();
        return ans;
    }
};