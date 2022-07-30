class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        vector<int> arr;
        int lastDigit = 0, len = 0;
        while (x > 0) {
            lastDigit = x % 10;
            arr.push_back(lastDigit);
            x = x/10;
            len ++; 
        }
        
        
        int i= (len%2)? /* odd */(len>>1)-1 : /* even */(len>>1)-1;
        int j = (len%2)? /* odd */(len>>1)+1 : /* even */(len>>1);        
        
        for (; i >= 0 && j<len; i--, j++) {
            if (arr[i]!=arr[j]) break;
        }
        
        return (i==-1 && j==len);
    }
};