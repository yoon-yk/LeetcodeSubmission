class Solution {
public:
    int numSquares(int n) {
        /*
        
        0 1 2 3 4 5 6 7 8 9 10 11 12 13
        1 1 2 3 1 2 3 4 2 2  3  4 
        1 1     1
        
        */
        
        vector<int> minSqs(n+1, 100000);
        minSqs[0] = 0;
        
        vector<int> curSquares;
        for (int i=0; i<=sqrt(n); i++) {
            curSquares.push_back(pow(i, 2));
        }
        
        
        for (int i=0; i<=n; i++) {
            for (int & curS : curSquares) {
                if (i-curS >= 0) {
                    minSqs[i] = min(minSqs[i], minSqs[i-curS] + 1);
                } else break;
            }
            
        }
        
        return minSqs[n];
    }
};