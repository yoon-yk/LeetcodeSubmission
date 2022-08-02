class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        
        vector<int> currWindow(26, 0);
        vector<int> pWindow(26, 0);
        
        int s_len = s.length(), p_len = p.length();
        if (s_len < p_len) return ans;
        
        for (int i=0; i<p_len; i++) {
            currWindow[s[i]-'a']++;
            pWindow[p[i]-'a']++;
        }
        
        int left = 0, right = p_len-1;
        
        while (right < s_len) {
                        
            if (currWindow == pWindow) {
                ans.push_back(left);
            }

            if (++right < s_len) {
                ++currWindow[s[right]-'a'];
            };
            
            --currWindow[s[left]-'a'];
            ++left;
        }
        
        return ans;
    }
};