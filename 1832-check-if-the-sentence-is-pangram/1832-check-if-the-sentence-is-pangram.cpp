class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> chars(26, 0);
        int cnt = 0;
        for (auto &ch : sentence) {
            if (chars[ch-'a'] == 0) cnt ++;
            chars[ch-'a']++;
        }
        
        return (cnt == 26);
    }
};