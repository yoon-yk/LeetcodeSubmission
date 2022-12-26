class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for (auto & word : words) {
            int i;
            for (i=0; i<pref.size() && pref[i] == word[i]; ++i);
            if (i==pref.size()) ++cnt;
        }
        return cnt;
    }
};