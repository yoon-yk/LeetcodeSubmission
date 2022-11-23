class Solution {
public:
    string decodeString(string s) {
     
        stack<char> st;
        stack<int> cntSt; 
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (s[i] == ']') {
                string ans;
                string finalStr;
                while (st.top() != '[') {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.pop();
                int cnt = cntSt.top(); cntSt.pop();
                for (int i=0; i<cnt; i++)
                    finalStr += ans;
                for (char& c : finalStr) 
                    st.push(c);
            } else if (isdigit(s[i])) {
                int j = i;
                string num;
                while (isdigit(s[j])) 
                    num += s[j++];
                i = j-1;
                cntSt.push(stoi(num));
            } else {
                st.push(s[i]);
            }
        }
        
        string ans; 
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};