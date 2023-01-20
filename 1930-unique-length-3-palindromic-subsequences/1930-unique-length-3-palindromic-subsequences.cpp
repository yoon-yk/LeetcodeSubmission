class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.size();
        vector<vector<int>> seen(26, vector<int>(26, 0));
        vector<int> left(26, 0), right(26, 0);
        for (int i=n-1; i>=0; --i) 
            ++right[s[i]-'a'];
        
        for (int i=0; i<n; ++i) { // i = center
            --right[s[i]-'a'];
            for (int k=0; k<26; ++k) {
                if (left[k] > 0 && right[k] > 0)  {
                    seen[s[i]-'a'][k] = true;
                }
            }
            ++left[s[i]-'a'];
        }
        
        int ans = 0;
        for (int i=0; i<26; ++i) {
            for (int j=0; j<26; ++j) {
                ans += seen[i][j];
            }
        }
        return ans;
    }
};