class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curPairs;
        backtack(0, n, curPairs, ans);
        
        return ans;
    }
    
    void backtack(int curOpens, int target, string &curPairs, vector<string>& ans) {
        
        if (curOpens > target || target < 0 ) return;
        
        if (curOpens == 0 && (target == 0)) 
            ans.push_back(curPairs);
        
        if (curOpens > 0) {
            curPairs.push_back(')');
            backtack(curOpens-1, target-1, curPairs, ans);
            curPairs.pop_back();
        }
        
        if (0 < target) {
            curPairs.push_back('(');
            backtack(curOpens+1, target, curPairs, ans);
            curPairs.pop_back();
        }
    }
};