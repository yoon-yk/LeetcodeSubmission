/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int numberOfPeople;
    
    int findCelebrity(int n) {
        numberOfPeople = n;
        for (int i=0; i<n; ++i) {
            if (isCelebrity(i)) return i;
        }
        return -1;
    }
    
    bool isCelebrity(int i){
        for (int j=0; j<numberOfPeople; ++j) {
            if (i == j) continue;
            if (knows(i, j) || !knows(j, i)) return false;
        }
        return true;
    }
};