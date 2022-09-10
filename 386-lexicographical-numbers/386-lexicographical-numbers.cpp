class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        for (int i=1; i<=9; i++)
            dfs(i, n, ans);
        return ans;    
    }
    
    void dfs (int &cur, int n, vector<int>& ans) {
        
        if (cur > n)
            return;
        
        ans.push_back(cur);

        int orig;
        for (int i=0; i<=9; i++) {
            orig = cur;
            cur*=10;
            cur+=i;
            dfs(cur, n, ans);
            cur = orig;
        }
    }
};