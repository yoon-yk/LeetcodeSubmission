vector<int> dict;
class Solution {
public:
    string customSortString(string order, string s) {
        dict.resize(26, INT_MAX);
        int oIdx = 0;
        for (auto & c : order)
            dict[c-'a'] = oIdx++;
        
        auto compare = [](char a, char b){
            return dict[a-'a'] < dict[b-'a'];
        };
        
        sort(s.begin(), s.end(), compare);
        
        return s;
    }
};