class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int num1, num2;
        int result = 0, curResult;
        stack<int> st;
        for (auto s : tokens) {
            if (s.size()>1 || isdigit(s[0]))
                    st.push(stoi(s));
            else{
                num2 = st.top(); st.pop();
                num1 = st.top(); st.pop();
                
                if (s == "+") 
                    curResult = (num1 + num2);
                else if (s == "-") 
                    curResult = (num1 - num2);
                else if (s == "*")
                    curResult = (num1 * num2);
                else if (s == "/") 
                    curResult = (num1 / num2);
                
                st.push(curResult);
            }

        }
        
        return st.top();
    }
};