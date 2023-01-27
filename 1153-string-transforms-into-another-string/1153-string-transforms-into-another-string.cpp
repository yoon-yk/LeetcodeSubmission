class Solution {
public:    
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        
        int sid1 = 0, sid2 = 0;
        vector<int> ids1(26, -1), ids2(26, -1);
        
        for (int i=0; i<str2.size(); ++i) {
            char & c1 = str1[i];
            char & c2 = str2[i];
            
            if (ids1[c1-'a'] == -1) ids1[c1-'a'] = sid1++;
            if (ids2[c2-'a'] == -1) ids2[c2-'a'] = sid2++;
            if (sid2 == 26 ||
                (ids1[c1-'a'] != i && ids1[c1-'a'] != ids2[c2-'a'])) return false;
        }

        return true;
        
    }
};