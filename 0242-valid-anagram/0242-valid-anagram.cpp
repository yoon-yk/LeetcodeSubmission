class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> freq(26, 0);
        
        for (auto & c : s) {
            ++freq[c-'a'];
        }
        
        for (auto& c : t) {
            if (--freq[c-'a'] < 0) 
                return false;
        }
        
        return true;
    }
};