// not on my own
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0; // final size
        int n = s.size();

        /*
        Forward Traversal:
        
        Traverse the string from start to end, updating the length based on whether you encounter a letter or a digit.

        */
        for (int i=0; i<n; ++i) {
            if ('a' <= s[i] && s[i] <= 'z') {
                ++size;
            } else {
                size *= s[i] - '0';
            }
        }

        /*
        Reverse Traversal:

        Start from the end of the string. 
        */

        for (int i=n-1; i>=0; --i) {
            char & ch = s[i];
            k %= size;
            if (isdigit(ch)) {
                // If you encounter a digit, divide the length by the digit and update k using modulo operation. 
                size /= ch-'0';
            } else {
                // If you encounter a letter and k equals 0,return the letter.
                if (k == 0)
                    return string(1, ch);
                --size;
            }
        }
        return "";
    }
};