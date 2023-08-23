class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26);
        for (auto & c : s) {
            ++count[c-'a'];
        }
        vector<pair<int, int>> v;
        for (int i=0; i<26; ++i) {
            if (count[i] == 0) continue;
            v.push_back({count[i], i});
        }

        sort(v.begin(), v.end(), greater());

        if (v[0].first > ((s.size()+1)/2)) return "";

        int idx = 0;
        for (auto & [cnt, ch] : v){
            while (cnt--) {
                s[idx] = ch + 'a';
                idx = (idx + 2);
                if (idx >= s.size()) idx = 1;
            }
        }

        return s;
    }
};