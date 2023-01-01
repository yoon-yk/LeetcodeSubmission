class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;
        for (auto & c : s) {
            if (c==')') {
                if (!st.empty()) st.pop();
                else ++ans;
            } else st.push(c);
        }
        return ans + st.size();
    }
};