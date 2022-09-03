class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {

        string curS;
        vector<int> ans;
        unordered_map<string, int> vis;
        
        for (int i=1; i<=9; i++) {
            curS = to_string(i);
            mutation (n, k, vis, curS, ans);
        }
        
        return ans;
    }
    
    void mutation (int n, int k, unordered_map<string, int>& vis, string& curS, vector<int>& ans) {
        
        if (curS.length() == n) {
            if (!vis.count(curS)) {
                vis[curS]++;
                ans.push_back(stoi(curS));
            }
            return;
        }
        
        int prev = curS.back() - '0';
        if (prev + k < 10) {
            curS += (prev + k) + '0';
            mutation(n, k, vis, curS, ans);
            curS.pop_back();
        }

        if (prev - k >= 0) {
            curS += (prev - k) + '0';
            mutation(n, k, vis, curS, ans);
            curS.pop_back();        
        }
        
    }
};