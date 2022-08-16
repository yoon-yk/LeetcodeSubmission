class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> t(n+1);
        int maxN = INT_MIN, mostT = -1;
        for (auto & pair : trust) {
            t[pair[0]]--; // out-degree
            t[pair[1]]++; // in-degree
  
        }
        
        int ans = -1;
        for (int i=1; i<=n; i++) 
            if (t[i] == n-1) {
                ans = i;
                break;
            }

        return ans;
        
    }
};