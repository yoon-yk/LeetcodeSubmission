class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans;
        dfs(s, 0, n-1, ans);
        return ans;
    }
    
    void dfs(string& s, int left, int right, string& subStr){
        
        int cntN; 
        string ans;
        for (int i=left; i<=right; i++) {
            if (isdigit(s[i])) {
                int j = i;
                string curN;
                while (j<=right && isdigit(s[j]))
                    curN += s[j++];
                cntN = stoi(curN);
                i = j-1;
            } else if (s[i] == '[') {
                int j = i+1;
                int leftB = 1, rightB = 0;
                while (j <= right && leftB > rightB) {
                    if (s[j] == '[') leftB ++;
                    else if (s[j] == ']') rightB++;
                    ++j;
                }
                if (leftB > 0) {
                    string tempStr;
                    dfs(s, i+1, j-2, tempStr);
                    for (int c=0; c<cntN; c++) 
                        ans += tempStr;
                }
                i = j-1;
            } else {
                ans += s[i];
            } 
        }
        subStr = ans;
    }
};