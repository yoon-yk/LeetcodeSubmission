class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        int cnt = 0;
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i=0; i<s1.size(); ++i) ++freq1[s1[i]-'a'], ++freq2[s2[i]-'a'];
        for (int i=0; i<26; ++i) {
            if (freq1[i] == freq2[i]) ++cnt;
        }
        if (cnt == 26) return true;
        
        int l, r;
        for (int i=s1.size(); i<s2.size(); ++i) {
            l = s2[i-s1.size()]-'a', r = s2[i]-'a';

            ++freq2[r];
            if (freq2[r] == freq1[r]) { // now equal
                ++cnt;
            } else if (freq2[r] == freq1[r]+1) { // was equal
                --cnt;
            }
            
            --freq2[l];
            if (freq2[l] == freq1[l]) { // now equal
                ++cnt;
            } else if (freq2[l]+1 == freq1[l]) { // was equal
                --cnt;
            }

            if (cnt == 26) return true;
        }
        return false;
        
    }
};