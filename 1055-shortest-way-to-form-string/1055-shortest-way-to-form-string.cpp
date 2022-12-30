class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int>> dict(26);
        for (int i=0; i<source.size(); ++i) dict[source[i]-'a'].push_back(i);
        int ans = 1, curIdx = -1, curCh;
        for (int i=0; i<target.size(); ++i) {
            curCh = target[i]-'a';
            if (dict[curCh].empty()) return -1;
            auto it = upper_bound(dict[curCh].begin(), dict[curCh].end(), curIdx);
            if (it == dict[curCh].end()) ++ans, curIdx = dict[curCh][0];
            else curIdx = dict[curCh][it-dict[curCh].begin()];
        }
        
        return ans;
    }
};