class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1Freq(26);
        for (char & c : s1) ++s1Freq[c-'a'];
        
        for (int i=0, j; i<s2.size(); ++i) {
            vector<int> s2Freq(26);
            for (j=0; i+j<s2.size(); ++j) {
                char & c = s2[i+j];
                ++s2Freq[c-'a'];
                if (s2Freq[c-'a'] > s1Freq[c-'a'])
                    break;
            }
            if (j == s1.size()) return true;
        }
        return false;
    }
};