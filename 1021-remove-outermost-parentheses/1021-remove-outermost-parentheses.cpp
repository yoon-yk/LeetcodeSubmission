class Solution {
public:
    string removeOuterParentheses(string s) {
        /*
        case 1 : (
        push to the stack
        case 2 : )
        if stack size == 1 - > pop
        else ans += 
        */
        stack<int> st;
        string ans;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                if (st.size() > 0)
                    ans += s[i];
                st.push('(');
            } else {                
                if (st.size() > 1)
                    ans += s[i];   
                st.pop();
            }
        }
        
        return ans;
    }
};