class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curPairs;
        backtack(0, 0, n, curPairs, ans);
        
        return ans;
    }
    
    void backtack(int curOpens, int curCloses, int target, string &curPairs, vector<string>& ans) {
        
        if (curOpens > target || curCloses > target) return;
        
        if (curOpens == 0 && (curCloses == target)) 
            ans.push_back(curPairs);
        
        if (curOpens > 0) {
            curPairs.push_back(')');
            backtack(curOpens-1, curCloses+1, target, curPairs, ans);
            curPairs.pop_back();
        }
        
        if (curCloses < target) {
            curPairs.push_back('(');
            backtack(curOpens+1, curCloses, target, curPairs, ans);
            curPairs.pop_back();
        }
    }
};