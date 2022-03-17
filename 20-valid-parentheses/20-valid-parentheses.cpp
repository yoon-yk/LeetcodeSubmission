class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2) return false;
        stack<char> st;
        int i=0;
        char cur = s[i];
        while (i<s.length()){
            if ((cur=='(')||(cur=='{')||(cur=='['))
                st.push(cur);
            else {
                if (st.empty()) return false;
                else if (cur==')') {
                    if (st.top()!='(') return false;
                    else st.pop();     
                }
                else if (cur==']') {
                    if (st.top()!='[') return false;
                    else st.pop();     
                }
                else if (cur=='}') {
                    if (st.top()!='{') return false;
                    else st.pop();     
                }                
            }

            cur = s[++i];
        }
        if (st.size()!=0) return false;
        return true;
    }
};