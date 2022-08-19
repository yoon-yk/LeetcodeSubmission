class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        string cur = "(";
        vector<string> ans;
        dfs(1, n-1, cur, ans);
        
        return ans;
    }
    
    void dfs(int opened, int remained, string& cur, vector<string>& ans) {
        
        if (opened == 0 && remained == 0) {
            ans.push_back(cur);
        }
        
        if (opened > 0) { // 열린거 하나 닫아주기
            cur += ")";
            dfs(opened-1, remained, cur, ans);
            cur.pop_back();
        }
        
        if (remained > 0) {
            cur += "(";
            dfs(opened+1, remained-1, cur, ans);
            cur.pop_back();
        }
        
    }
};