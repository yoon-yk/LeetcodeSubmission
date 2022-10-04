class Solution {
public:
    int numSquares(int n) {
        
        vector<int> sqrNums;
        
        for (int i=1; i <= sqrt(n); i++)
            sqrNums.push_back(i*i);
        
        queue<int> q;
        q.push(n);
        
        int level = 0, size; 
        
        while (q.size() > 0) {
            level ++;
            
            size = q.size();
            while (size--) {
                int curN = q.front(); q.pop();
                for (int & sqr : sqrNums) {
                    if (curN == sqr) {
                        return level;
                    } else if (curN > sqr) {
                        q.push(curN - sqr);
                    }
                }
            }
            
        }
        
        return level;
    }
};