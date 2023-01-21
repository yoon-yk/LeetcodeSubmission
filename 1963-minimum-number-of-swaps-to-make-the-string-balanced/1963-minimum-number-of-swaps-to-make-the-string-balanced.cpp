class Solution {
public:
    int minSwaps(string s) {
        int opens = 0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '[') {
                ++opens;
            } else {
                if (opens > 0) --opens;
            }
            
            /*
            "][][]]][[[[][]][[]]["   
            */
        }
    
        return (opens+1) >> 1;
    }
};