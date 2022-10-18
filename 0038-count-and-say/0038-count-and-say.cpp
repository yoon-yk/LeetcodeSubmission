class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 0) return "";
        
        string curStr = "1";
        for (int i=2; i<=n; i++) {
            string nextStr;
            int j, count, digit;
            for (int i=0; i<curStr.size();) {
                j = i;
                while (j<curStr.size() && curStr[j]==curStr[i]) j++;
                count = j-i;
                digit = curStr[i];
                nextStr += to_string(j-i); nextStr+= digit;
                i = j;
            }
            curStr = nextStr;
        }        
        return curStr;
    }
};