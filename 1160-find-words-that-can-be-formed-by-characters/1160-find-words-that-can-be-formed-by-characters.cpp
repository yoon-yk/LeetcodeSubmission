class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> dict(26, 0);
        for (auto & c : chars)
            dict[c-'a'] ++;
        
        int cnt = 0;
        for (auto & word : words) {
            bool isGood = true;
            vector<int> curDict(26, 0);
            for (auto & ch : word) {
                ++curDict[ch-'a'];
                if (curDict[ch-'a'] > dict[ch-'a']){
                    isGood = false;
                    break;
                }
            }
            if (isGood)
                cnt += word.size();
        }
        
        return cnt;
    }
};