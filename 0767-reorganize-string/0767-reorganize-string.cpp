class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char & c : s) ++freq[c-'a'];
        int mf = *max_element(freq.begin(), freq.end());
        if (mf > ((s.size()+1) >> 1)) return "";
        
        priority_queue<pair<int, char>> pq;
        for (int i=0; i<26; ++i) if (freq[i]) pq.push({freq[i], i+'a'});
        
        string ans(s.size(), ' ');
        int idx = 0;
        while (!pq.empty()) {
            auto [f, c] = pq.top(); pq.pop();
            while (f > 0) {
                if (ans[idx] != ' ') ++idx;
                else {
                    ans[idx] = c;
                    --f, idx += 2;
                    if (idx >= s.size()) idx %= s.size();
                }

            }
        }
        
        return ans;
    }
};