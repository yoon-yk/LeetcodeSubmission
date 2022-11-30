class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> dict(26);
        
        for (int i=0; i<s.size(); i++) {
            dict[s[i]-'a'].push_back(i);
        }
        
        int cnt = 0;
        for (auto & word : words) {
            int curIdx = -1;
            bool found = true;
            for (int i=0; i<word.size(); i++) {
                vector<int>& curVector = dict[word[i]-'a'];
                auto nextIdx = upper_bound(begin(curVector), end(curVector), curIdx);
                if (nextIdx == end(curVector)) {
                    found = false;
                    break;
                }
                curIdx = curVector[nextIdx-begin(curVector)];
            }
            cnt += found;
        }
        
        return cnt;
    }
};