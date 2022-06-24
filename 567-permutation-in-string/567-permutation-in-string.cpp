class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // edge cases
        if(s1.size()>s2.size()) return false;
        
        int slen1 = s1.size(), slen2 = s2.size();
        int start = 0, end = 0;
        
        unordered_map<char, int> hashM; 
        for (auto i:s1) hashM[i]++;
        int count = hashM.size();
        
        while (end<slen2){
            if (hashM.find(s2[end])!=hashM.end()){
                hashM[s2[end]]--;
                if (hashM[s2[end]]==0) count--;
            }

            if (end-start+1 < slen1) end++;
            else if (end-start+1 == slen1) {
                if (count == 0)
                    return true;
                if (hashM.find(s2[start])!=hashM.end()){
                    hashM[s2[start]]++;
                    if (hashM[s2[start]]==1) count++;
                }
                start++; end++;
            }
        }
        
        return false;
    }
};