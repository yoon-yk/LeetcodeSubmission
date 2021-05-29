class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0) return 0;
        int MAX_INT = 2147483647;
        int MIN_INT = -2147483648;
        int i=0, neg = 0;
        long long ans=0;
        
        // check whitespace
        while(s[i]==' ') i++;
        
        // check sign
        if(s[i]=='-'){neg=1; i++;}
        else if(s[i]=='+') i++;
        
        if(!isdigit(s[i])) return 0;
        while(isdigit(s[i])){
            ans = ans*10 + (s[i++]-'0');
            if(neg&&(-1)*ans<MIN_INT) return MIN_INT;
            if(!neg&&ans>MAX_INT) return MAX_INT;
        }
        
        // multiply -1 if neg 
        if(neg) ans *= -1;
        
        return ans;
    }
};