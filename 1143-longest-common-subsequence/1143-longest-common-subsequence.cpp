class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> memo(n+1, vector<int> (m+1, -1));
        return dpSolve(text1, text2, 0, 0, memo);
    }
    
    int dpSolve(string & text1, string & text2, int p1, int p2, vector<vector<int>>& memo) {
               
        if (memo[p1][p2] != -1) 
            return memo[p1][p2];
    
        if (p1 == text1.size() || p2 == text2.size()) 
            return memo[p1][p2] = 0; 
        
        int answer = 0;
        if (text1[p1] == text2[p2])
            answer = 1 + dpSolve(text1, text2, p1+1, p2+1, memo);
        else 
            answer = max(dpSolve(text1, text2, p1, p2+1, memo), dpSolve(text1, text2, p1+1, p2, memo));
        
        return memo[p1][p2] = answer;
    }

};