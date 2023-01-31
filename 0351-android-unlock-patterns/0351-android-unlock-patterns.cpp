class Solution {
public:
    
    unordered_map<int, unordered_map<int, int>> mp {
        {1, {{3, 2}, {7, 4}, {9, 5}}},
        {2, {{8, 5}}},
        {3, {{1, 2}, {7, 5}, {9, 6}}}, 
        {4, {{6, 5}}}, 
        {5, {}}, 
        {6, {{4, 5}}},
        {7, {{1, 4}, {3, 5}, {9, 8}}}, 
        {8, {{2, 5}}}, 
        {9, {{1, 5}, {3, 6}, {7, 8}}}
    };
    
    int numberOfPatterns(int m, int n) {
        int visited = 0;
        /*
        1 2 3
        4 5 6
        7 8 9
        */
        vector<vector<vector<int>>> dp(10, vector<vector<int>>(1<<10, vector<int>(10, -1)));
        return backtrack(0, visited, n, dp) - backtrack(0, visited, m-1, dp);
    }
    

    
    int backtrack(int n, int visited, int maxCnt, vector<vector<vector<int>>>& dp) {
        
        if (maxCnt == 0) return 0;
        if (dp[n][visited][maxCnt] != -1) return dp[n][visited][maxCnt];
        
        int mid, ans = 0;
        for (int next=1; next<=9; ++next) {
            if (visited & (1 << next)) continue; // 방문한적 있다면 skip
            // 거쳐야 하는 애 확인 
            if (!mp[n].count(next) || (visited & (1 << mp[n][next]))){
                ans += (backtrack(next, (visited | (1 << next)), maxCnt-1, dp) + 1);
            }
        }
        
        return dp[n][visited][maxCnt] = ans;
    }
};