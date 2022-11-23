class Solution {
public:
    int minimumRecolors(string blocks, int k) {
       
        // make a window
        // count the black blocks
        // curans = (k-cntBlk)
        
        // while (end<n) 
        //  add next blck
        //  discard head blck
        //  update curans
        
        int blckCnt = 0;
        for (int i=0; i<k; i++) {
            if (blocks[i] == 'B')
                blckCnt ++;
        }
        
        int maxBCnt = blckCnt;
        
        for (int end=k, start=0; end<blocks.size(); end++, start++) {
            if (blocks[end] == 'B')
                blckCnt ++;
            if (blocks[start] == 'B')
                blckCnt --;
            maxBCnt = max(maxBCnt, blckCnt);
        }
        
        return k - maxBCnt;
        
    }
};