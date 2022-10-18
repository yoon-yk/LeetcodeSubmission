class Solution {
public:
    string countAndSay(int n) {
        
        if (n == 1)
            return "1";
        string curStr = countAndSay(n-1);
        
        string ans;
        int j, count, digit;
        for (int i=0; i<curStr.size();) {
            j = i;
            while (j<curStr.size() && curStr[j]==curStr[i]) {
                j++;
            }
            count = j-i;
            digit = curStr[i];
            ans += to_string(j-i); ans+= digit;
            i = j;
        }
        
        return ans;
    }
};