class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size(), curCh, left = 0, right = 0;
        int ans = 0, maxCount = 0;
        vector<int> dict(26, 0);
        for (;right<n; right++) {
            curCh = s[right]-'A';
            dict[curCh]++;
            maxCount = max(maxCount, dict[curCh]);
            
            if ((right-left+1) - maxCount > k) {
                dict[s[left]-'A']--;
                // maxCount = max(maxCount, dict[s[left]-'A']);
                left++;
            } 
            ans = max(ans, right-left+1);
        }
        
        return ans;
    }
};