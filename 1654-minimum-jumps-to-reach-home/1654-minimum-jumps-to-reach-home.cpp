class Solution {
public:

    unordered_map<int,int> m; // Stores forbidden positions
    int dp[7001][2];

    int solve(int i, bool back, int a, int b, int x){

        // What are all these arguments?
        // i: stores the index
        // back: 'true' if previous step was a 'back', else 'false'
        // a: front step size
        // b: back step size
        // x: target position

        // We have reached the target
        if (i == x) return 0;
        
        // Check if the index is valid or not 
        if ( (i < 0) or (m.find(i)!= m.end()) or (i > 6000) )
            return 1e9; // Return infinity, it is not possible to compute the result
        
        // If result has already been computed
        if(dp[i][back]!=-1) return dp[i][back];
        
        // Go forward
        dp[i][back] = 1 + solve(i+a, 0, a, b, x);        
        // If last move was not a 'back', go backward
        if(!back) dp[i][back] = min(dp[i][back], 1 + solve(i-b, 1, a, b, x));

        return dp[i][back];
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // Add forbidden positions
        for(const int a : forbidden) m[a] = 1;
        // Set default values to '-1'
        memset(dp,-1,sizeof(dp));
        // Get solution 
        int ans = solve(0, 0, a, b, x);
        // Why '1e9'? 1e9 is used like infinity here.
        if(ans >= 1e9) return -1; // Solution not found
        return ans;
    }
};