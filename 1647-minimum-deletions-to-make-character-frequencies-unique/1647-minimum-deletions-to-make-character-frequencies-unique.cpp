class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        vector<int> freq(26, 0);
        for (auto & c : s) ++freq[c-'a'];
        sort(freq.begin(), freq.end(), greater<>());
        
        /*
        3 3 2
        3 2 1 
        
        5 4 1
        5 5 1
        */
        
        int prev = freq[0] + 1;
        for (auto & cnt : freq) {
            if (prev <= cnt) {
                ans += (cnt-(prev-1));
                cnt = prev-1;
            } 
            prev = max(cnt, 1);
        }
        
        return ans;
    }
};