class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s2.size() < s1.size()) return false;
        
        // fixed size sliding window
        int s2Len = s2.size();
        vector<int> dict(26, 0);
        int cnt = 0, found = 1;
        for (int i=0; i<s1.size(); i++) {
            if (dict[s1[i]-'a'] == 0) cnt++;
            dict[s1[i]-'a']++;
            
            if (dict[s2[i]-'a'] == 1) cnt--;
            dict[s2[i]-'a']--;
        }
        
        if (cnt == 0) return true;
       
        int start = 0;
        for (int end=s1.size(); end<s2.size(); end++, start++) {
            if (dict[s2[end]-'a'] == 1) cnt--;
            dict[s2[end]-'a']--;
            
            if (dict[s2[start]-'a'] == 0) cnt++;
            dict[s2[start]-'a']++;
            
            if (cnt == 0)
                return true;
        }
        
        
        return false;
    }
};