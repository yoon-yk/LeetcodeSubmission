class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> frontChoice(k+1, 0), rearChoice(k+1, 0);
        for (int i=0; i<k; i++) 
            frontChoice[i+1] = frontChoice[i] + cardPoints[i];
        
        for (int i=0; i<k; i++) 
            rearChoice[i+1] = rearChoice[i] + cardPoints[(n-1)-i];

        /*
        arr = [1 2 3 4 5 6 1]
        fc  = [0 1 3 6 10 15 21 22]
        rc  = [0 1 7 12 16 19 21 22]
        */
        
        int maxAns = -1;
        for (int i=0; i<=k; i++) {
            maxAns = max(maxAns, frontChoice[i] + rearChoice[k-i]);
        }
        
        return maxAns;
    }
};