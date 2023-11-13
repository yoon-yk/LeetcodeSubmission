class Solution {
public:
    string sortVowels(string s) {
        string temp;
        unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };
        for (auto & c : s) {
            if (vowels.count(c)) {
                temp += c;
            }
        }
        sort(temp.begin(), temp.end());

        string ret;
        int idx = 0;
        for (auto & c : s) {
            if (vowels.count(c)) {
                ret += temp[idx];
                ++idx;
            } else {
                ret += c;
            }
        }
        return ret;
    }
};