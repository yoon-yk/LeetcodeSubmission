class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        /*
        arr = [1 2 3 4 5 6 1]
        fc  = [0 1 3 6 10 15 21 22]
        rc  = [0 1 7 12 16 19 21 22]
        */
        
        int curSum = 0;
        for (int i=0; i<k; i++) {
            curSum += cardPoints[i];
        }
        
        int maxAns = curSum;
        for (int i=0; i<k; i++) {
            curSum = curSum - cardPoints[k-1-i]+ cardPoints[n-1-i];
            maxAns = max(maxAns, curSum);
        }
        
        return maxAns;
    }
};