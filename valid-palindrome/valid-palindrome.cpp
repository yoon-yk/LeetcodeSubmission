class Solution {
public:
    string plainString(string s){
        string temp="";
        for(auto &c:s){
            if(('a'<=c&&c<='z')||('A'<=c&&c<='Z')||('0'<=c&&c<='9'))
                temp+=tolower(c);
        }
        return temp;
    }
    bool isPalindrome(string s) {
        int i, j;
        s = plainString(s);
        if(s.size()==0) return true;
        
        for(i=0, j=s.size()-1; ((s[i]==s[j])&&(i<j)); i++, j--);
        if(i>=j) return true;
        return false;
    }
};