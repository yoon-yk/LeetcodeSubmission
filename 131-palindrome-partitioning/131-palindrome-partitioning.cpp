class Solution {
public:

    bool isPalindrome(string& s, int front, int back, vector<vector<int>>& dp) {
        
        if (dp[front][back] != -1) 
            return dp[front][back];
        
        if (s[front] == s[back] && (back-front<=2 || dp[front+1][back-1])) 
            return dp[front][back] = true;
        
        return dp[front][back] = false;
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
            ans.emplace_back(curPath);
            return;
        }
        
        for (int end = start; end < n; end++) {
            if (isPalindrome(s, start, end, dp)) {
                curPath.emplace_back(s.substr(start, end-start+1));
                dfs(end+1, s, dp, curPath, ans);
                curPath.pop_back();
            }
        }
    }
    
};