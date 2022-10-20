class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s1.size() > s2.size()) return false;
        vector<int> dict1(26, 0), dict2(26, 0);
        int len1 = s1.size(), len2 = s2.size();
        for (int i=0; i<len1; i++) {
            dict1[s1[i]-'a']++;
            dict2[s2[i]-'a']++;
        }
        if (dict1 == dict2) return true;
        
        int curCh, startCh;
        for (int end=len1; end<len2; end++) {
            curCh = s2[end] - 'a';
            dict2[curCh]++;
            
            startCh = s2[end-len1] - 'a';
            dict2[startCh]--;
            
            if (dict1 == dict2) return true;
        }
        
        return false;
    }
};