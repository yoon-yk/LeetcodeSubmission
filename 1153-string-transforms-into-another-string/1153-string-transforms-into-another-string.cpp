class Solution {
public:    
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        
        int sid1 = 0, sid2 = 0;
        vector<int> ids1(26, -1), ids2(26, -1);
        vector<int> parent1(str1.size());
        
        for (int i=0; i<str1.size(); ++i) {
            char & c = str1[i];
            if (ids1[c-'a'] == -1) ids1[c-'a'] = sid1++;
            parent1[i] = ids1[c-'a'];
        }
        
        for (int i=0; i<str2.size(); ++i) {
            char & c = str2[i];
            if (ids2[c-'a'] == -1) ids2[c-'a'] = sid2++;
            
            if (sid2 == 26 ||
                (parent1[i] != i && parent1[i] != ids2[c-'a'])) return false;
        }

        return true;
        
    }
};