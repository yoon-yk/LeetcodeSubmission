class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size()==0 || p.size()==0 || p.size() > s.size()) return {};
        
        vector<int> res;
        
        // 1. put every chars of p into a hashMap 
        unordered_map<char, int> hashM;
        for(auto ch:p) hashM[ch]+=1;
        
        // 2. sliding window 
        int start=0, end=0, cnt=hashM.size();
        while (end<=s.size()) {
            if (hashM.find(s[end])!=hashM.end()) {
                hashM[s[end]] --;
                if (hashM[s[end]] == 0) cnt--;
            }
            
            if (end-start+1 < p.size()){
                end++;
            } else if (end-start+1 == p.size()) {
                if (cnt == 0) res.push_back(start);
                if (hashM.find(s[start])!=hashM.end()) {
                    hashM[s[start]] ++;
                    if (hashM[s[start]] == 1) cnt++;
                }
                start++; end++;
            }
            
        }
        
        return res;
    }
};