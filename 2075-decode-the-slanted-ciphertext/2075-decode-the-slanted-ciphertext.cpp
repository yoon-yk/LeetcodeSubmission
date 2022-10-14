class Solution {
public:
    
    /*
    
    [ ,b, ]
    [ ,a,c]
    
    */
    
    int deleteTrailingSpace(string &str) {
        int i=str.size()-1;
        while (i>=0 && str[i] == ' ') {
            i--;
        }
        return i;
    }
    
    string interpretCode(string &encodedText, int startingIdx, int gapSize) {
        string ans;
        int size = encodedText.size();
        while (startingIdx < size) {
            ans += encodedText[startingIdx];
            startingIdx += gapSize;
        }
        
        // int delIdx = deleteTrailingSpace(ans);
        // return (delIdx < 0 ) ? "" : ans.substr(0, delIdx+1);
        return ans;
    }
    
    string decodeCiphertext(string encodedText, int rows) {
        /*
        00 01 02 03 04
        05 06 07 08 09
        10 11 12 13 14
        

        */
        string ans;
        int totalLen = encodedText.size();
        int rowSize = totalLen / rows;
        int gapSize = rowSize + 1;
        
        // for (int i=totalLen-rowSize; i>0; i-=rowSize) {
        //     ans += interpretCode(encodedText, i, gapSize);
        // }
        
        for (int i=0; i<rowSize; i++) {
            ans += interpretCode(encodedText, i, gapSize);
        }

        int delIdx = deleteTrailingSpace(ans);
        return (delIdx < 0 ) ? "" : ans.substr(0, delIdx+1);
        
        // return ans;
    }
};