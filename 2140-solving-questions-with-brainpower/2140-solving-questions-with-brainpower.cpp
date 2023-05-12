class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solution(0, questions, dp);
    }
    
    long long solution(int idx, vector<vector<int>>& questions, vector<long long>& dp) {
    
        if (idx >= questions.size()) {
            return 0;
        }
        
        if (dp[idx] != -1) {
            return dp[idx];
        }
        
        int p = questions[idx][0], bp = questions[idx][1];
        // solve
        long long solve = solution(idx + bp + 1, questions, dp) + p;
        
        // skip
        long long skip = solution(idx+1, questions, dp);
        
        return dp[idx] = max(solve, skip);
    }
};