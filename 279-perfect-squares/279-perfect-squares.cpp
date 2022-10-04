class Solution {
public:
    set<int> sqrNums;
    
    bool isDividedBy(int n, int count) {
        if (count == 1)
            return sqrNums.count(n);
        
        for (auto & sqr : sqrNums) {
            if (isDividedBy(n-sqr, count-1))
                return true;
        }
        
        return false;
    }
    
    int numSquares(int n) {
        sqrNums.clear();
        
        for (int i=1; i*i <= n; i++)
            sqrNums.insert(i*i);
        
        int count = 1;
        for (;count<=n; count++) {
            if (isDividedBy(n, count))
                return count;
        }
        
        return count;
    }
};