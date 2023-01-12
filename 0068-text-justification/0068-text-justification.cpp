class Solution {
public:    
    vector<string> fullJustify(vector<string> words, int l) {
    int idx=0; 
    vector<string> ans;
    for (int r=0, len=l; idx < words.size();++r, len=l) {
        string curRow;
        int bIdx = idx, eIdx = idx;
        for (; eIdx<words.size() && len-(int)words[eIdx].size()>=0; ++eIdx) {
            len -= (int)words[eIdx].size() + 1;
        }
        ++len; // last word space

        int curWordsCnt = eIdx-bIdx;
        if (curWordsCnt == 1 || eIdx == words.size()) { // left justification
            for (int i=bIdx; i<eIdx; ++i) {
                curRow += words[i];
                if (i < eIdx-1) curRow += ' ';
            }
            curRow += string(len, ' ');
        } else {
            int gapSize = len / (curWordsCnt-1);
            int spaceLeft = len % (curWordsCnt-1);
            for (int i=bIdx; i<eIdx; ++i) {
                curRow += words[i];
                if (spaceLeft > 0) curRow += ' ', --spaceLeft;
                if (i < eIdx-1) curRow += string(gapSize + 1, ' ');
            }
        }
        ans.push_back(curRow);
        idx = eIdx;
    }
    return ans;
    }

};