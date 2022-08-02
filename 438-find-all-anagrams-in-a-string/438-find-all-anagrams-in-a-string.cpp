class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        int left = 0, right = 0, slen = s.length(), plen = p.length();
        
        unordered_map<char, int> pdict;
        
        for (int i=0; i<plen; i++) {
            if (pdict.count(p[i]))
                pdict[p[i]]++;
            else pdict[p[i]] = 1;
        }
        
        int charN = pdict.size();
            
        while ( right < slen ) {
                        
            // 1. Check if s[right] exists in string p
            if (pdict.find(s[right])!=pdict.end()) { 
                --pdict[s[right]];
                
                if (pdict[s[right]] == 0)
                    --charN;
            } 

            // 2. If the window size is equal to plen
            if (right-left+1 == plen) { 

                // If every characters are consumed 
                if (charN == 0) {
                    ans.push_back(left);
                }
                
                // Restore left one if it's from the dict
                if (pdict.find(s[left])!=pdict.end()) { 
                    if (pdict[s[left]] == 0)
                        ++charN; 
                    ++pdict[s[left]]; 
                }

                // Move left
                ++left;
            }
            
            ++right;
        }
        
        return ans;
    }
};