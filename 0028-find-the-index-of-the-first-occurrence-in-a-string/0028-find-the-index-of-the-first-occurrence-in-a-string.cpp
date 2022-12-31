class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i=0; i<haystack.size(); ++i) {
            int j=i, np = 0;
            while (np < needle.size() && haystack[j] == needle[np]) ++np, ++j;
            if (np == needle.size()) return i;
        }
        return -1;
    }
};