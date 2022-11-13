class Solution {
public:
    bool isPalindrome(string s) {
        int firstPtr = 0, lastPtr = s.size()-1;
        while (firstPtr < lastPtr) {
            // cout << s[firstPtr] << " : " << s[lastPtr] << endl;
            if (!isalnum(s[firstPtr])) firstPtr++;
            else if (!isalnum(s[lastPtr])) lastPtr--;
            else if (isdigit(s[firstPtr]) && isdigit(s[lastPtr]) && s[firstPtr]!= s[lastPtr]) return false;
            else if (tolower(s[firstPtr]) != tolower(s[lastPtr])) return false;
            else firstPtr ++,lastPtr --;
        }
        return true;
    }
};