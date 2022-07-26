class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        
        vector<int> ans;
        
        int size = s.length();
        vector <int> accumPlate (size); // index should be of the candle 
        vector <int> memS (size);
        vector <int> memE (size);

        int cntCandle = -1, idxS = 0;
        int currPlate = 0;
        
        for (int i=0; i<size; i++) {
            
            if (s[i] == '*'){ // encounter the plate
                if (cntCandle >= 0)  //*** 여기서 등호 안써줘서 맨 처음에 '|'로 시작하는애 카운트 안해줌요 ㅠ 
                    currPlate ++; // 2. count the plates until the closing candle
                // 1. discard all plates until the first candle
            }
            else if (s[i] == '|') { // encounter the candle
                ++cntCandle;
                accumPlate[cntCandle] = currPlate; // 3. add up the plates when encountering the closing candle
            }
            memS[i] = idxS; if(s[i] == '|') idxS++;
            memE[i] = cntCandle;
        }
        
        
        for (vector<int>& query : queries) {
            int currSum = 0;
            int start = query[0], end = query[1];
            if (memS[start] < memE[end])
                currSum = accumPlate[memE[end]]-accumPlate[memS[start]];
            ans.push_back(currSum);
        }
        
        int i = 0;
        
        for (int i=0; i<memS.size(); i++) {
            printf("%3d", i);
        }
        cout << endl;
        
        for (auto next:memS) {
            printf("%3d", next);
        }
        cout << endl;
        
        i = 0;
        for (auto next:memE) {
            printf("%3d", next);
        }
        cout << endl;
        
//         i = 0;
//         for (auto next:mem) {
//             cout << i++ << "|" << next << endl;
//         }
        
        return ans;
        
        
        /*
        
          0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20 
 


         
         0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
         * * | * * | * * * |  *  *  *  *  *  |  *  |  *  |  *
[memS]   0 0 0 1 1 1 2 2 2 2  3  3  3  3  3  3  4  4  5  5  6
[memE]  -1-1 0 0 0 1 1 1 1 2  2  2  2  2  2  3  3  4  4  5  5
  

idxS = cntCandle (before adding up)

idxE = cntCandle - 1;

[memS]<[memE] 
          
[candle] [0]-0
         [1]-2
         [2]-5
         [3]-10
         [4]-11
          
---------------------------
[intv]   [0]-[ 2, 5] 
         [1]-[ 5, 9]
         [2]-[ 9,15]
         [3]-[15,17]
         [4]-[17,19]

[plate]  [0]-[2]
         [1]-[3]
         [2]-[5]
         [3]-[1]
         [4]-[1]
         
[accum]  [0]-[ 2]
         [1]-[ 5]
         [2]-[10]
         [3]-[11]
         [4]-[12]
         
        */
    }
};