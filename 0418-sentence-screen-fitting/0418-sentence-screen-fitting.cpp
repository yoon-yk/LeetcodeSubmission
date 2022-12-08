class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        
        int n = sentence.size();
        vector<int> cycleNext(n, -1), cycleCnt(n, -1);

        bool cycle = false, space = false;
        int startStr = 0, cnt = 0, set = 0;
        int rowsLeft = rows-1, colsLeft = cols;
        int cycleStart = -1, prevCnt = 0;
        while (!cycle) {
            for (int i=0; !cycle && i<n; i++){
                int wordSize = sentence[i].size();
                if (colsLeft < (wordSize + space)) {
                    if (rowsLeft == 0) return set;
                    cycleNext[startStr] = i;
                    cycleCnt[startStr] = set - prevCnt;
                    prevCnt = set;
                    if (cycleCnt[i]!= -1) { cycle = true, cycleStart = i; break;}
                    --rowsLeft;
                    colsLeft = cols;
                    space = false;
                    startStr = i;
                }
                colsLeft -= (wordSize + space);
                space = true;
            }
            if (!cycle) ++set;
        }

        int idx = cycleStart;
        while (rowsLeft--) {
            set += cycleCnt[idx];
            idx = cycleNext[idx];
        }        
        
        return set;
        
    }
};