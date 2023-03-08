class Solution {
public:
    int countTime(string time) {
        // a b c d
        
        int hourComb = 1, minComb = 1;
        // if ab is missing
        if (time.substr(0, 2) == "??") {
            hourComb = 24;
        } else if (time[0] == '?') {
            if (time[1]-'0' <= 3) {
                hourComb = 3;
            } else {
                hourComb = 2;
            }
        } else if (time[1] == '?') {
            if (time[0]-'0' <= 1) {
                hourComb = 10;
            } else if (time[0]-'0' == 2) {
                hourComb = 4;
            } else {
                hourComb = 0;
            }
        }
        
        
        if (time.substr(3, 2) == "??") {
            minComb = 60;
        } else if (time[3] == '?') {
            minComb = 6;
        } else if (time[4] == '?') {
            minComb = 10;
        }   
        
        
        return hourComb * minComb;
    }
};