class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1, len = s.length();
        while (left < right) {
            while (left < len && !isalpha(s[left]) && !isdigit(s[left]))
                left++;
            while (right >= 0 && !isalpha(s[right])&& !isdigit(s[right]))
                right--;
            if (left >= right) return true;
            if (tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};