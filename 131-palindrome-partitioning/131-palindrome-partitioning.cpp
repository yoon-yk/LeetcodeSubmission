class Solution {
public:

    bool isPalindrome(string& s, int front, int back) {
        
        while (front < back) {
            if (s[front] != s[back]) return false;
            front++, back--;
        }
        return true;
    }
    
    vector<vector<string>> partition(string &s) {

        int n = s.length();
        vector<string> curPath;
        vector<vector<string>> ans;
        
        string newStr;
        backtrack(ans, s, 0, curPath);
        return ans;
    }
    
    void backtrack(vector<vector<string>>& ans, string &s, int start, vector<string> &curPath) {
        if (start == s.length())
            ans.emplace_back(curPath);
        
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                curPath.emplace_back(s.substr(start, end-start+1));
                backtrack(ans, s, end+1, curPath);
                curPath.pop_back();
            }
        }
    }
    
};