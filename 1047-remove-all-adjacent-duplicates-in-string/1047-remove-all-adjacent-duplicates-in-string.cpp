class Solution {
public:
    
    /*bcacd*/
    void palindromeOdd(string& s, int i) {
        int left = i-1, right = i+1;
        while (left >= 0 && right < s.size()) {
            while (left >= 0 && s[left] == '-') left--;
            while (right < s.size() && s[right] == '-') right ++;
            if (left < 0 || right >= s.size() || s[left] != s[right]) break;
            s[left] = '-', s[right] = '-';
            break;
            // left --, right ++;
        }
    }
    
    void palindromeEven(string& s, int &i, vector<bool>& deleted) {
        int left = i, right = i+1;
        while (left >= 0 && right < s.size()) {
            while (left >= 0 && deleted[left]) left--;
            while (right < s.size() && deleted[right]) right ++;
            if (left < 0 || right >= s.size() || s[left] != s[right]) break;
            deleted[left] = true, deleted[right] = true;
            left --, right ++;
        }
        i = right-1;
    }
    
    string removeDuplicates(string s) {
        
        vector<bool> deleted(s.size(), false);
        
        for (int i=0; i<s.size(); i++) {
            // palindromeOdd(s, i);
            palindromeEven(s, i, deleted);
        } 
        
        // cout << s << endl;
        string ans;
        for (int i=0; i<s.size(); i++) {
            if (!deleted[i])
                ans += s[i];
        }
        return ans;
    }
};