class Solution {
public:
    
    /*
    
    [ ,b, ]
    [ ,a,c]
    
    */
    
    string& interpretCode(string &ans, string &encodedText, int startingIdx, int gapSize) {
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
        
        for (int i=0; i<rowSize; i++) {
            string newStr;
            ans += interpretCode(newStr, encodedText, i, gapSize);
        }

        while (!ans.empty() && ans.back() == ' ')
            ans.pop_back();
        
        return ans;
    }
};