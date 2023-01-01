class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0;
        int right = 0;
        for (auto & c : s) {
            if (c==')') {
                if (left > 0) --left;
                else ++right;
            } else ++left;
        }
        return left + right;
    }
};