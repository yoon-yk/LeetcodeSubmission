class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int beginIdx = 0, endIdx = k-1;
        int blackCnt = 0;
        
        for (int i=0; i<k; i++)
            if (blocks[i] == 'B') ++blackCnt;               

        if (blackCnt == k) 
            return 0;
        
        
        int len = blocks.length();
        int curMax = blackCnt;
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