class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        
        int rowsLeft = rows-1, colsLeft = cols;
        int set = 0;
        bool space = false;
        
        int n = sentence.size();
        vector<int> cycleNext(n, -1);
        vector<int> cycleCnt(n, -1);
        int startStr = 0, cnt = 0;
        
        /*
        i       0 
        apple   0
        pie     1
        had     1
        
        */
        string word;
        bool cycle = false;
        int cycleStart = -1;
        int prevCnt = 0;
        while (!cycle) {
            for (int i=0; !cycle && i<n; i++){
                word = sentence[i];
                if (colsLeft < (word.size() + space)) {
                    if (rowsLeft == 0) return set;
                    // cout << endl;
                    cycleNext[startStr] = i;
                    cycleCnt[startStr] = set - prevCnt;
                    prevCnt = set;
                    if (cycleCnt[i]!= -1) { cycle = true, cycleStart = i; break;}
                    --rowsLeft;
                    colsLeft = cols;
                    space = false;
                    startStr = i;
                }
                // cout << word << " ";
                if (space) --colsLeft;
                colsLeft -= word.size();
                space = true;
            }
            if(!cycle) ++set;
        }
        
        // cout <<"rowsLeft " << rowsLeft << endl;
        int rowIdx = 0;
        int cycleSize = cycleCnt.size()-cycleStart;
        // for (auto i : cycleCnt)
        //     cout << i << " ";
        // cout << endl;
        // for (auto i : cycleNext)
        //     cout << i << " ";
        // cout << endl;
        
        int idx = cycleStart;
        while (rowsLeft--) {
            set += cycleCnt[idx];
            idx = cycleNext[idx];
        }        
        
        return set;
        
        /*
        
        8x7
        i_had__
        apple__
        pie_i__
        had____
        apple__
        pie_i__
        had____
        apple__
        
        2x8
        ________ hello___
        ________ world___
        
        3x6
        a_bcd_
        e__a__
        bcd_e_
        
        // if longest sentence < cols -> 0
        
        int set = 0
        while (rowsLeft > 0) {
            for (word : sentence){
                if (colsLeft < word.size()) {
                    if (rowsLeft == 0) return set;
                    rowsLeft--;
                    colsLeft = cols;
                    space = false;
                }
                if (space) colsLeft--;
                colsLeft -= word.size();
            }
            ++set;
        }
        
        i-had
        apple
        pie-i
        had--
        apple
        pie-i
        had--
        
         
         i_had_apple_pie_i
         had_apple_pie_i__
         had_apple_pie_i__
         ...
         
         i_had_apple
         _pie_i_had_
         apple_pie_i
         had_apple__
         pie_i_had__
         apple_pie_i
         
         
         i_had_apple_pie_i__
         had_apple_pie_i_had
         apple_pie_i_had____
         apple_pie_i_had____
         
        
        */
        
        
        
        
        
        
    }
};