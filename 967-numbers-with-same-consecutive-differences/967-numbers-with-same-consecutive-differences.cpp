class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {

        vector<int> ans;
        
        for (int i=1; i<=9; i++)
            mutation (n-1, k, i, ans);
        
        return ans;
    }
    
    void mutation (int n, int k, int& curN, vector<int>& ans) {
        
        if (n == 0) {
            ans.push_back(curN);
            return;
        }
        
        int prev = curN % 10;
        if (prev + k < 10) {
            curN = curN * 10 + (prev + k);
            mutation(n-1, k, curN, ans);
            curN /= 10;
        }

        if (k!= 0 && (prev - k) >= 0) {
            curN = curN * 10 + (prev - k);
            mutation(n-1, k, curN, ans);
            curN /= 10;
        }
        
    }
};