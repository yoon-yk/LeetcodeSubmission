class Solution {
public:    

    int lengthLongestPath(string s) {
        string name;
        vector<int> st(1, 0);
        int tabCnt = 1, curLen = 0, ans = 0;
        
        for (int i=0; i<=s.size(); ++i) {
            if (i==s.size() || s[i] == '\n') {
                if (name.find(".") != name.npos) { // file name 
                    ans = max(ans, st[tabCnt-1] + curLen);
                } else { // potential folder name 
                    if (st.size() == tabCnt) st.push_back(0);
                    st[tabCnt] = st[tabCnt-1] + 1 + curLen;
                }
                name.clear();
                curLen = 0, tabCnt = 1;
            } else if (s[i] == '\t') { // count tab size
                ++tabCnt;
            } else { // collect name
                ++curLen;
                name += s[i];
            }
        }
        return ans;
    }


};