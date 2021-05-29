class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        if(s.size()==0) return true;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        int i;
        for(i=0; (s[i]==t[i]&&i<s.size()); i++);
        if(i!=s.size()) return false;
        return true;
    }
};