class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int beginIdx = 0, endIdx = 0;
        int blackCnt = 0;
        
        for (; endIdx<k; endIdx++)
            if (blocks[endIdx] == 'B') ++blackCnt;               

        if (blackCnt == k) 
            return 0;
        
        int len = blocks.length();
        int curMax = blackCnt;
        endIdx--;
        
        while (endIdx < len) {
            
            ++endIdx;
            if (blocks[endIdx] == 'B') ++blackCnt;
            
            if (blocks[beginIdx] == 'B') --blackCnt;
            ++beginIdx;

            curMax = max(curMax, blackCnt);
        }
        
        return k-curMax;
        
    }
};