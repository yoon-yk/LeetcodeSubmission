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
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        dfs(0, s, dp, curPath, ans);
        
        return ans;
    }
    
    void dfs(int start, string& s, vector<vector<int>>& dp, vector<string> &curPath, vector<vector<string>>& ans) {
        int n = s.size();
        if (start == n){
            ans.push_back(curPath);
            return;
        }
        
        for (int end = start; end < n; end++) {
            if (dp[start][end] == -1)
                dp[start][end] = isPalindrome(s, start, end);
            if (dp[start][end] == 1) {
                curPath.push_back(s.substr(start, end-start+1));
                dfs(end+1, s, dp, curPath, ans);
                curPath.pop_back();
            }
        }
    }
    
};