class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans, curV;
        unordered_map<int, int> vis;
        for (int i=1; i<=9; i++) {
            curV.push_back(i);
            mutation (n, k, vis, curV, ans);
            curV.pop_back();
        }
        
        return ans;
    }
    
    void mutation (int n, int k, unordered_map<int, int>& vis, vector<int>& curV, vector<int>& ans) {
        
        if (curV.size() == n) {
            int curN = 0;
            for (int i=0; i<n; i++)
                curN = curN*10 + curV[i];
            
            if (!vis.count(curN)) {
                vis[curN]++;
                ans.push_back(curN);
            }
                
            return;
        }
        
        
        if (!curV.empty()) {
            int prev = curV.back();
            if (prev + k < 10) {
                curV.push_back(prev + k);
                mutation(n, k, vis, curV, ans);
                curV.pop_back();
            }
                
            if (prev - k >= 0) {
                curV.push_back(prev - k);
                mutation(n, k, vis, curV, ans);
                curV.pop_back();        
            }
        }
        
    }
};