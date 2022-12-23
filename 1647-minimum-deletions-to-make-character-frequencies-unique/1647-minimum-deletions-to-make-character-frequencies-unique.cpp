class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        vector<int> freq(26, 0);
        for (auto & c : s) ++freq[c-'a'];
        sort(freq.begin(), freq.end(), greater<>());
        
        int prev = freq[0] + 1;
        for (auto & cnt : freq) {
            if (cnt == 0) break;
            if (prev <= cnt) {
                ans += (cnt-(prev-1));
                cnt = prev-1;
            } 
            prev = max(cnt, 1);
        }
        
        return ans;
    }
};