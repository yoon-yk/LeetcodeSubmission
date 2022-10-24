class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> bits(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<arr[i].size(); j++) {
                if (bits[i] & (1 << (arr[i][j]-'a'))){
                    bits[i] = -1;
                    break;
                }
                bits[i] |= (1 << (arr[i][j]-'a'));
            }
        }
        
        for (int i=0; i<n; i++)
            cout << bits[i] << endl;
        
        vector<unordered_map<int, int>> dp(n);
        return backtrack(arr, bits, 0, 0, dp);
    }
    
    int backtrack(vector<string>& arr, vector<int>& bits, int idx, int curBits, vector<unordered_map<int, int>>& dp) {
                    
        if (idx == arr.size())
            return 0;
        
        if (dp[idx].count(curBits))
            return dp[idx][curBits];

        int ans = 0;
        
        if (bits[idx] != -1 && (curBits & bits[idx]) == 0) 
            ans = max(ans, backtrack(arr, bits, idx+1, curBits | bits[idx], dp) + (int)arr[idx].size());
        
        ans = max(ans, backtrack(arr, bits, idx+1, curBits, dp));
        
        return dp[idx][curBits] = ans;
    }
};