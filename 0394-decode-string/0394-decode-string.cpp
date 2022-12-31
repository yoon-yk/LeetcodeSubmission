class Solution {
public:
    string decodeString(string& s) {
        int idx = 0;
        return dfs(s, idx);
    }
    
    string dfs(string& s, int& idx) {
        string ans, num, msg;
        int cnt;
        for (; idx<s.size(); idx++) {
            char& c = s[idx];
            if (isdigit(c)) {
                num += c;
            } else if (c == ']') {
                return ans;
            } else if (c == '[') {
                ++idx;
                cnt = stoi(num);
                num.clear();
                string newStr = dfs(s, idx);
                for (int i=0; i<cnt; ++i)
                    ans += newStr;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};