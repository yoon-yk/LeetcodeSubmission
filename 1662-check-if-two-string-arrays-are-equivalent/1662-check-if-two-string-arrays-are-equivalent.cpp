class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1Idx = 0, w2Idx = 0; 
        int c1Idx = 0, c2Idx = 0;
        
        while (w1Idx<word1.size() && w2Idx< word2.size()) {
            
            if (word1[w1Idx][c1Idx] != word2[w2Idx][c2Idx])
                return false;
            
            c1Idx++, c2Idx++;
            
            if (c1Idx == word1[w1Idx].size()) {
                w1Idx ++;
                c1Idx = 0;
            }
            
            if (c2Idx == word2[w2Idx].size()) {
                w2Idx ++;
                c2Idx = 0;
            }
            
        }
        
        if (w1Idx<word1.size() || w2Idx< word2.size() ||
            c1Idx || c2Idx) return false;
        
        return true;
    }
};