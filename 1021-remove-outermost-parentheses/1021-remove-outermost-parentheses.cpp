class Solution {
public:
    string removeOuterParentheses(string s) {
        deque<int> st;
        
        /*
        (()())(())
        */
        int open = 0;
        string ans;
        for (char & c : s) {
            if (c == '(') {
                ++open;
            } else if (c == ')') {
                --open;
            }
            st.push_back(c);
            if (open == 0) {
                st.pop_front();
                while (st.size() > 1) {
                    ans.push_back(st.front());
                    st.pop_front();
                }
                st.pop_back();
            }
        }
        return ans;
    }
};