class Solution {
public:
    string convertToTitle(int num) {
      string ret;
        while (num) {
          --num;
          ret += (char)(num % 26 + 'A');
          num /= 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};